#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string m_target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void doSomething() const override;

		std::string getTarget() const;
};

#endif
