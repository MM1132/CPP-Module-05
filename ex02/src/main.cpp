#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubbery_test(Bureaucrat& executor)
{
	std::cout << "shrubbery_test" << std::endl;

	ShrubberyCreationForm form("<target_name>");

	form.beSigned(executor);

	form.execute(executor);
}

void robotomy_test(Bureaucrat& executor)
{
	std::cout << "robotomy_test" << std::endl;

	RobotomyRequestForm form("<target_name>");

	form.beSigned(executor);

	form.execute(executor);
}

void presidential_test(Bureaucrat& executor)
{
	std::cout << "presidential_test" << std::endl;

	PresidentialPardonForm form("<target_name>");

	form.beSigned(executor);

	executor.executeForm(form);
	// form.execute(executor);
}

int main()
{
	Bureaucrat executor("my_bureaucrat", 10);

	shrubbery_test(executor);
	std::cout << std::endl;
	
	robotomy_test(executor);
	std::cout << std::endl;

	presidential_test(executor);
	std::cout << std::endl;

	return 0;
}
