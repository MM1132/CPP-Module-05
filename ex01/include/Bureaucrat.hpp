#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	static const constexpr int GRADE_MIN = 150;
	static const constexpr int GRADE_MAX = 1;

	private:
		const std::string m_name;
		int m_grade;

	public:
		// The orthodox canonical form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const noexcept;
		int getGrade() const noexcept;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override
				{
					return "Grade is too low";
				}
		};

		void incrementGrade();
		void decrementGrade();

		void signForm(Form& form);

		static void checkGradeThrowError(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
