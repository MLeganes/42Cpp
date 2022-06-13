#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

/* Error:
 * Form.hpp:31:16: error: ‘Bureaucrat’ has not been declared
 *   31 |  void beSigned(Bureaucrat &bure);
 *      |                ^~~~~~~~~~
 * Error fix:
 * Add the line 16
 */
class Bureaucrat;


class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:
	Form();
	Form(const Form &copy);
	Form(const std::string name, int signGrade, int executeGrade);
	~Form();

	Form &operator=(const Form &copy);

	
	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void beSigned(Bureaucrat &bure);

	// Exception class Declaration. NO Orthodox Canonical Form.
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	// Exception class Declaration. NO Orthodox Canonical Form.
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(const std::ostream &ost, Form &form);

#endif
