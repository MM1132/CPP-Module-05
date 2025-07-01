#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExec):
	m_name(name),
	m_isSigned(false),
	m_gradeRequiredToSign(gradeRequiredToSign),
	m_gradeRequiredToExec(gradeRequiredToExec)
{
	if (m_gradeRequiredToSign < 1 || m_gradeRequiredToExec < 1)
		throw AForm::GradeTooHighException();
	if (m_gradeRequiredToSign > 150 || m_gradeRequiredToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other):
	m_name(other.m_name),
	m_isSigned(other.m_isSigned),
	m_gradeRequiredToSign(other.m_gradeRequiredToSign),
	m_gradeRequiredToExec(other.m_gradeRequiredToExec)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->m_isSigned = other.m_isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

// End of the Orthodox Canonical Form stuff
std::string AForm::getName() const
{
	return this->m_name;
}

bool AForm::getIsSigned() const
{
	return this->m_isSigned;
}

int AForm::getGradeRequiredToSign() const
{
	return this->m_gradeRequiredToSign;
}

int AForm::getGradeRequiredToExec() const
{
	return this->m_gradeRequiredToExec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->m_gradeRequiredToSign)
		throw AForm::GradeTooLowException();
	this->m_isSigned = true;
}

void AForm::setIsSigned(bool isSigned)
{
	this->m_isSigned = isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Signed: " << form.getIsSigned() << std::endl;
	os << "Grade reuiqred to sign: " << form.getGradeRequiredToSign() << std::endl;
	os << "Grade reuiqred to exec: " << form.getGradeRequiredToExec() << std::endl;
	return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (this->getGradeRequiredToExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
	
	this->doSomething();
}
