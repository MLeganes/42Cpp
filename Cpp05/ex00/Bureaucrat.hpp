#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int 				_grade;	// 1 Highest 150 Lowest

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &ope);

	void				setGrade(int grade);
	const std::string	&getName() const;
	int					getGrade() const;

	void				increaseGrade();
	void				decreaseGrade();


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
std::ostream &operator<<(std::ostream &ost, Bureaucrat &bure);

#endif