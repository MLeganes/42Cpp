#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}
Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		// this->_name = copy.getName();
		this->_isSigned = copy.getIsSigned();
		// this->_signGrade = copy.getSignGrade();
		// this->_executeGrade = copy.getExecuteGrade();
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return this->_name;
}
bool Form::getIsSigned() const
{
	return (this->_isSigned);
}
int Form::getSignGrade() const
{
	return (this->_signGrade);
}
int Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void Form::beSigned(Bureaucrat &person2sign)
{
	// If the bureaucrat’s grade is high enough (higher or egal to the required one).
	// Remember, grade 1 is higher than grade 2.
	if (person2sign.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

// Exception class Declaration. NO Orthodox Canonical Form.
const char *Form::GradeTooHighException::what() const throw()
{
	return ("error: Form: Increasing grade out of range, too high");
}

// Exception class Declaration. NO Orthodox Canonical Form.
const char *Form::GradeTooLowException::what() const throw()
{
	return ("error: Form: Decreasing grade out of range, too low");
}

std::ostream &operator<<(std::ostream &ost, Form &form)
{
	ost << "Form name " << form.getName()
		<< " signed: " << (form.getIsSigned() ? "True" : "False")
		<< " sign grade: " << form.getSignGrade()
		<< " execute grade " << form.getExecuteGrade() << std::endl;
	return (ost);
}
