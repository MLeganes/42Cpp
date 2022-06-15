#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("defaultBureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->_name = copy.getName();
	this->setGrade(copy.getGrade());

	// Other way to construct.
	//*this = copy;

	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	this->_name = name;
	this->setGrade(grade);
	std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->setGrade(copy.getGrade());
	}
	return (*this);
}

void Bureaucrat::setName(std::string &name)
{
	this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade()
{
	this->setGrade(this->_grade - 1);
}
void Bureaucrat::decreaseGrade()
{
	this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << *this << " signed " << form << WHITE << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		throw Bureaucrat::NoSignException();
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << *this << " executed " << form << WHITE << std::endl;
	}
	catch (const AForm::NoSignedFormException &e)
	{
		throw Bureaucrat::NoExecutionSignException();
	}
	catch (const  AForm::GradeTooLowException &e)
	{
		throw Bureaucrat::NoExecutionGradeLowException();
	}
}

// Exception implementation
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("error: Bureaucrat: Grade too high");
};

// Exception implementation
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("error: Bureaucrat: Grade too low");
};

// Exception implementation
const char *Bureaucrat::NoSignException::what() const throw()
{
	return ("error: Bureaucrat: No signed because the grade is too low");
};

// Exception implementation
const char *Bureaucrat::NoExecutionSignException::what() const throw()
{
	return ("error: Bureaucrat: No execution because form is not signed");
};

// Exception implementation
const char *Bureaucrat::NoExecutionGradeLowException::what() const throw()
{
	return ("error: Bureaucrat: No execution because grade is low");
};

// Function to the Bureaucrat class.
std::ostream &operator<<(std::ostream &ost, const Bureaucrat &bure)
{
	ost << bure.getName() << ", bureaucrat grade " << bure.getGrade();
	return (ost);
}
