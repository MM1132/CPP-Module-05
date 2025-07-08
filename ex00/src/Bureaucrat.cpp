#include "Bureaucrat.hpp"
#include <iostream>

// Dies ist der Standardkonstruktor für den Fall, dass wir nichts angeben
Bureaucrat::Bureaucrat() :
	m_name("<undefined_bureaucrat_name>"), m_grade(Bureaucrat::GRADE_MIN)
{}

// Dies ist für den Fall, dass wir Namen und Grad angeben
Bureaucrat::Bureaucrat(std::string name, int grade):
	m_name(name)
{
	// Überprüfung des Grades hier. Wenn alles in Ordnung ist, wird es einfach weitergehen
	Bureaucrat::checkGradeThrowError(grade);
	m_grade = grade;
}

// Das ist die cupy konstruktor
Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade) {};

// Dies ist fur den equals ooperator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// We can only change the grade, as name is constant
		this->m_grade = other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << m_name << " has been deconstructed now :c" << std::endl;
}

// END OF ORTHODOX CANONICAL FORM

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

void Bureaucrat::checkGradeThrowError(int grade)
{
	if (grade < Bureaucrat::GRADE_MAX)
		throw GradeTooHighException();
	if (grade > Bureaucrat::GRADE_MIN)
		throw GradeTooLowException();
}

// This is one of the most confusing parts here
// But we can understand it so there is no problem really
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
