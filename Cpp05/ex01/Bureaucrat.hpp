#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

/* Error:
 * Bureaucrat.hpp:30:19: error: ‘Form’ has not been declared
 * 30 |  void    signForm(Form &form);
 *    |                   ^~~~
 * Error fix:
 * Add the line 16
 */
class Form;

class Bureaucrat
{
private:
	std::string _name;
	int 		_grade;	// 1 Highest 150 Lowest

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &ope);

	void				setName(std::string &name);
	void				setGrade(int grade);
	const std::string	&getName() const;
	int					getGrade() const;

	void				increaseGrade();
	void				decreaseGrade();
	void				signForm(Form &form);


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

// Overload of the insertion («) operator
// Atention: It must be out of the class!!!
std::ostream &operator<<(std::ostream &ost, const Bureaucrat &bure);

#endif