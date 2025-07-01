#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	Intern someRandomIntern;

	AForm* rrf;
	AForm* secondForm;

	// Options: "shrubbery request", "robotomy request", "presidential request"
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	secondForm = someRandomIntern.makeForm("presidentiall request", "Bender");
	
	delete rrf;
	delete secondForm;

	return 0;
}
