#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _isSigned(copy.isSigned()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	std::cout << "AForm " << this->_name << " copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm default deconstructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		// this->_name = copy.getName();
		this->_isSigned = copy.isSigned();
		// this->_signGrade = copy.getSignGrade();
		// this->_executeGrade = copy.getExecuteGrade();
	}
	return (*this);
}

const std::string &AForm::getName() const
{
	return this->_name;
}
bool AForm::isSigned() const
{
	return (this->_isSigned);
}
int AForm::getSignGrade() const
{
	return (this->_signGrade);
}
int AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void AForm::beSigned(Bureaucrat &person2sign)
{
	// If the bureaucrat’s grade is high enough (higher or egal to the required one).
	// Remember, grade 1 is higher than grade 2.
	if (person2sign.getGrade() > this->getSignGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_isSigned = true;
}

// Exception class Declaration. NO Orthodox Canonical AForm.
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("error: Form: Increasing grade out of range, too high");
}

// Exception class Declaration. NO Orthodox Canonical AForm.
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("error: Form: Decreasing grade out of range, too low");
}

// Exception class Declaration. NO Orthodox Canonical AForm.
const char *AForm::NoSignedFormException::what() const throw()
{
	return ("error: Form: NO signed");
}

std::ostream &operator<<(std::ostream &ost, const AForm &form)
{
	ost << "Form name " << form.getName()
		<< " signed: " << (form.isSigned() ? "True" : "False")
		<< " sign grade: " << form.getSignGrade()
		<< " execute grade: " << form.getExecuteGrade();
	return (ost);
}
