#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:
	AForm();
	AForm(const AForm &copy);
	AForm(const std::string name, int signGrade, int executeGrade);
	virtual ~AForm();

	AForm &operator=(const AForm &copy);

	
	const std::string	&getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void beSigned(Bureaucrat &bure);
	virtual void execute(const Bureaucrat &executor) const = 0;

	// Exception class Declaration. NO Orthodox Canonical AForm.
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	// Exception class Declaration. NO Orthodox Canonical AForm.
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	// Exception class Declaration. NO Orthodox Canonical AForm.
	class NoSignedFormException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &ost, const AForm &form);

#endif
