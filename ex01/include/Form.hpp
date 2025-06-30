#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeRequiredToSign;
		const int m_gradeRequiredToExec;

	public:
		// Orthodox canonical form
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Getters for all
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExec() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Form grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Form grade too low";
				}
		};

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
