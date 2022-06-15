#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default_PresidentialPardonForm")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade()), _target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &)
{
	return (*this);
}

void				PresidentialPardonForm::setTarget(const std::string &target)
{
	this->_target = target;
}
const std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
	{
		throw AForm::GradeTooLowException();
	}
	if (this->isSigned() == false)
	{
		throw AForm::NoSignedFormException(); 
	}
	 std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
