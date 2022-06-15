#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_ShrubberyCreationForm")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade()), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &)
{
	return (*this);
}

void				ShrubberyCreationForm::setTarget(const std::string &target)
{
	this->_target = target;
}
const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
	{
		throw AForm::GradeTooLowException();
	}
	if (this->isSigned() == false)
	{
		throw AForm::NoSignedFormException(); 
	}

	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	if (file.is_open() == false)
	{
		std::cout << "Error: file \"" << (this->_target + "_shrubbery") << "\" can not be opened "  << std::endl;
		return ;
	}
	file	<< "                               ,@@@@@@@@@,					\n"
	"                       ,,,.   ,@@@@@@/@@@@,  .oo8888o.			\n"
	"                    ,&%%&%&&%,@@@@@/@@@@@@@@,8888\\88/8o		\n"
	"                   ,%&\\%&&%&&%,@@@\\@@@@@/@@@88\\88888/88'	\n"
	"                   %&&%&%&/%&&%@@\\@@/   /@@@88888\\88888'		\n"
	"                   %&&%/ %&%%&&@@\\ V ///@@' `88\\8 `/88'	\n"
	"                   `&%\\ ` /%&'    |.|          \\ '|8'	\n"
	"                       |o|         | |           | |\n"
	"                       |.|         | |           | |\n"
	"                     \\/ ._\\//_/__/  ,,,\\_//__\\\\/.  \\_//__/_\n";
	file.close();
}
