#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string m_name;
		bool m_isSigned;
		const int m_gradeRequiredToSign;
		const int m_gradeRequiredToExec;

	public:
		// Orthodox canonical form
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Getters for all
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExec() const;

		void setIsSigned(bool isSigned);

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Form must be signed to execute";
				}
		};

		void beSigned(const Bureaucrat& bureaucrat);

		void execute(Bureaucrat const & executor) const;
		virtual void doSomething() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
