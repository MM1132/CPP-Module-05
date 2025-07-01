#include <string>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

// Orthodox canonical form stuff VV

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other.getName(), 
	other.getGradeRequiredToSign(), 
	other.getGradeRequiredToExec()), 
	m_target(other.getTarget())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->m_target = other.getTarget();
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Orthodox canonical form stuff ^^

void ShrubberyCreationForm::doSomething() const
{
	std::string fileName(this->m_target + std::string("_shrubbery"));
	std::ofstream file(fileName);

	if (file.is_open())
	{
		file << "       *       " << std::endl;
		file << "      ***      " << std::endl;
		file << "     *****     " << std::endl;
		file << "    *******    " << std::endl;
		file << "   *********   " << std::endl;
		file << "  ***********  " << std::endl;
		file << " ************* " << std::endl;
		file << "***************" << std::endl;
		file << "      |||      " << std::endl;
		file << "      |||      " << std::endl;
		file << std::endl;
		
		file << "        /\\        " << std::endl;
		file << "       /  \\       " << std::endl;
		file << "      /    \\      " << std::endl;
		file << "     /      \\     " << std::endl;
		file << "    /        \\    " << std::endl;
		file << "   /          \\   " << std::endl;
		file << "  /            \\  " << std::endl;
		file << " /______________\\ " << std::endl;
		file << "        ||        " << std::endl;
		file << "        ||        " << std::endl;
		
		file.close();
	}
	else
	{
		throw std::runtime_error("Could not open file " + fileName);
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->m_target;
}
