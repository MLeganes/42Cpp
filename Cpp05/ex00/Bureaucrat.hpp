#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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

	Bureaucrat *operator=(Bureaucrat const &ope);

	void			setName(std::string &name);
	void			setGrade(int grade);
	std::string	&getName() const;
	int				getGrade() const;

	// Exception Declaration
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Bureaucrat::GradeTooHighException");
			}
	};
	
	// Exception Declaration
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Bureaucrat::GradeTooLowException");
			}
	};
};

#endif