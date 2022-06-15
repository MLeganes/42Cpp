#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"

int main()
{
	std::cout << GREEN << std::endl << " 1). Test " << WHITE << std::endl;
	try
	{
		/***
		 *
		 * Bureaucrat Test
		 *
		 ***/
		// Bureaucrat constructor
		Bureaucrat bur("Administrator", 148);

		
		/***
		 *
		 * ShrubberyCreationForm Test
		 *
		 ***/
		// Form Constructor
		ShrubberyCreationForm scForm("FormularShrubberyEx02");

		try
		{
			// Exception no-sign formular
			//bur.signForm(scForm);

			// Exceptioin no-execution
			//bur.executeForm(scForm);

			bur.setGrade(10);
			bur.signForm(scForm);
			bur.executeForm(scForm);
		}
		catch (const Bureaucrat::NoSignException &e)
		{
			std::cout << RED << bur << " couldn’t sign " << scForm << " because " << e.what() << WHITE << std::endl;
		}
		catch (const Bureaucrat::NoExecutionSignException &e )
		{
			std::cout << RED << bur << " couldn’t execute " << scForm << " because " << e.what() << WHITE << std::endl;
		}
		catch (const Bureaucrat::NoExecutionGradeLowException &e)
		{
			std::cout << RED << bur << " couldn’t execute " << scForm << " because " << e.what() << WHITE << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
