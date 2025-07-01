#include <string>
#include <fstream>

#include "PresidentialPardonForm.hpp"

// Orthodox canonical form stuff VV

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other.getName(), 
	other.getGradeRequiredToSign(), 
	other.getGradeRequiredToExec()), 
	m_target(other.getTarget())
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->m_target = other.getTarget();
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Orthodox canonical form stuff ^^

void PresidentialPardonForm::doSomething() const
{
	std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->m_target;
}
