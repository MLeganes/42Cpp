#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default_RobotomyRequestForm")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade()), _target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _target(target)
{
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &)
{
	return (*this);
}

void				RobotomyRequestForm::setTarget(const std::string &target)
{
	this->_target = target;
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
	{
		throw GradeTooLowException();
	}
	if (this->isSigned() == false)
	{
		throw NoSignedFormException(); 
	}
	std::cout << RED << std::endl << "Start drilling..." << std::endl;
	std::cout << "drilling..." << std::endl;
	std::cout << "drilling..." << std::endl;
	std::cout << "End drilling!" <<  WHITE << std::endl;
	
	if (arc4random() % 2 == 1)
		std::cout << this->_target <<  " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->_target <<  " attempt to robotomize failed!" << std::endl;
}
