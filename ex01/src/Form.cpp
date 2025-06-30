#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExec):
	m_name(name),
	m_isSigned(false),
	m_gradeRequiredToSign(gradeRequiredToSign),
	m_gradeRequiredToExec(gradeRequiredToExec)
{
	if (m_gradeRequiredToSign < 1 || m_gradeRequiredToExec < 1)
		throw Form::GradeTooHighException();
	if (m_gradeRequiredToSign > 150 || m_gradeRequiredToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other):
	m_name(other.m_name),
	m_isSigned(other.m_isSigned),
	m_gradeRequiredToSign(other.m_gradeRequiredToSign),
	m_gradeRequiredToExec(other.m_gradeRequiredToExec)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->m_isSigned = other.m_isSigned;
	}
	return (*this);
}

Form::~Form() {}

// End of the Orthodox Canonical Form stuff
std::string Form::getName() const
{
	return this->m_name;
}

bool Form::getIsSigned() const
{
	return this->m_isSigned;
}

int Form::getGradeRequiredToSign() const
{
	return this->m_gradeRequiredToSign;
}

int Form::getGradeRequiredToExec() const
{
	return this->m_gradeRequiredToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->m_gradeRequiredToSign)
		throw Form::GradeTooLowException();
	this->m_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Signed: " << form.getIsSigned() << std::endl;
	os << "Grade reuiqred to sign: " << form.getGradeRequiredToSign() << std::endl;
	os << "Grade reuiqred to exec: " << form.getGradeRequiredToExec() << std::endl;
	return os;
}
