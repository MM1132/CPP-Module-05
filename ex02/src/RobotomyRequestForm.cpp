#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

// Orthodox canonical form stuff VV

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other.getName(), 
	other.getGradeRequiredToSign(), 
	other.getGradeRequiredToExec()), 
	m_target(other.getTarget())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->m_target = other.getTarget();
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Orthodox canonical form stuff ^^

void RobotomyRequestForm::doSomething() const
{
	srand(time(0));
	int randomNumber = rand() % 2;

	if (randomNumber)
		std::cout << "*some drilling noises*... " << this->m_target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->m_target;
}
