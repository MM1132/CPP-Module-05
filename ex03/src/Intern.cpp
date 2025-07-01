#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern() {}


// #######################

AForm* Intern::makeForm(std::string formName, std::string formTarget) const
{
	std::string forms[] = { "shrubbery request", "robotomy request", "presidential request" };
	
	int index = 0;
	while (index < 3 && formName.compare(forms[index]))
		index++;

	switch (index)
	{
		case 0:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
	}

	std::cout << "Intern didn't find the form to create :c" << std::endl;
	return NULL;
}
