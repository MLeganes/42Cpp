#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"

int main()
{
	std::cout << GREEN << std::endl
			  << " 1). Test Intern" << WHITE << std::endl;
	try
	{
		Bureaucrat bs[4] = {
			Bureaucrat("Presi", 1),
			Bureaucrat("Vice", 30),
			Bureaucrat("Robot", 50),
			Bureaucrat("Shrubbery", 150)};
		Intern intern;
		AForm *fs[4] = {
			intern.makeForm("RobotomyRequestForm", "my car"),
			intern.makeForm("PresidentialPardonForm", "himself"),
			intern.makeForm("NotExistingForm", "intern"),
			intern.makeForm("ShrubberyCreationForm", "church's garden")};

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (fs[j] != 0L)
				{
					try{
						bs[i].signForm(*fs[j]);
					}
					catch (const Bureaucrat::NoSignException &e)
					{
						std::cout << RED << bs[i] << " couldn’t sign " << *fs[j] << " because " << e.what() << WHITE << std::endl;
					}
					catch (const Bureaucrat::NoExecutionSignException &e)
					{
						std::cout << RED << bs[i] << " couldn’t execute " << *fs[j] << " because " << e.what() << WHITE << std::endl;
					}
					catch (const Bureaucrat::NoExecutionGradeLowException &e)
					{
						std::cout << RED << bs[i] << " couldn’t execute " << *fs[j] << " because " << e.what() << WHITE << std::endl;
					}
				}
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (fs[j] != 0L)
				{
					try{
						bs[i].executeForm(*fs[j]);
					}
					catch (const Bureaucrat::NoSignException &e)
					{
						std::cout << RED << bs[i] << " couldn’t sign " <<*fs[j] << " because " << e.what() << WHITE << std::endl;
					}
					catch (const Bureaucrat::NoExecutionSignException &e)
					{
						std::cout << RED << bs[i] << " couldn’t execute " << *fs[j] << " because " << e.what() << WHITE << std::endl;
					}
					catch (const Bureaucrat::NoExecutionGradeLowException &e)
					{
						std::cout << RED << bs[i] << " couldn’t execute " << *fs[j] << " because " << e.what() << WHITE << std::endl;
					}
				}
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
