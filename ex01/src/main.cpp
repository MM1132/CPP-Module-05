#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tests_ex00()
{
	std::cout << "tests_ex00:" << std::endl;

	// Bureaucrat invalidBureaucrat = Bureaucrat("invalid_bureaucrat", 151);

	Bureaucrat bureaucrat = Bureaucrat("my_bureaucrat", 5);

	std::cout << bureaucrat << std::endl;

	// Incrementing grade
	for (int i = 0; i < 10; i++)
	{
		try
		{
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << bureaucrat << std::endl;

	// Decrementing grade
	for (int i = 0; i < 10; i++)
	{
		try
		{
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << bureaucrat << std::endl;
}

void tests_ex01()
{
	std::cout << "tests_ex01:" << std::endl;

	Bureaucrat myBureaucrat("my_bureaucrat", 51);
	Form myForm("my_form", 50, 10);

	try
	{
		myBureaucrat.signForm(myForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << myBureaucrat << std::endl;
	std::cout << myForm << std::endl;

}

int main()
{
	tests_ex00();
	std::cout << std::endl;
	
	tests_ex01();
	std::cout << std::endl;

	return 0;
}