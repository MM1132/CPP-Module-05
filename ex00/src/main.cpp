#include <iostream>

#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat invalidBureaucrat = Bureaucrat("invalid_bureaucrat", 151);

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

	std::cout << "Program ended" << std::endl;

	return 0;
}