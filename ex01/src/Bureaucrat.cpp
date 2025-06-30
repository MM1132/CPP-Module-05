#include "Bureaucrat.hpp"
#include <iostream>

// VV All the stuff that every Class we create has anyways
Bureaucrat::Bureaucrat() :
	m_name("<undefined_bureaucrat_name>"), m_grade(Bureaucrat::GRADE_MIN)
{}

Bureaucrat::Bureaucrat(std::string name, int grade):
	m_name(name)
{
	Bureaucrat::checkGradeThrowError(grade);
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade) {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->m_grade = other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << m_name << " has been deconstructed now :c" << std::endl;
}

// ^^ All the stuff that every Class we create has anyways

std::string Bureaucrat::getName() const noexcept
{
	return this->m_name;
}

int Bureaucrat::getGrade() const noexcept
{
	return this->m_grade;
}

void Bureaucrat::incrementGrade()
{
	if (m_grade == Bureaucrat::GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade == Bureaucrat::GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->m_name << " signed " << form.getName() << "" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->m_name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::checkGradeThrowError(int grade)
{
	if (grade < Bureaucrat::GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	if (grade > Bureaucrat::GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
