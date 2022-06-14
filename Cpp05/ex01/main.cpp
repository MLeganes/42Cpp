#include "Bureaucrat.hpp"

#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"

int main()
{
	std::cout << GREEN << std::endl
			  << " 1). Test " << WHITE << std::endl;
	try
	{
		/***
		 *
		 * Bureaucrat Test
		 *
		 ***/
		// Bureaucrat constructor
		Bureaucrat bur("Administrator", 100);

		// Bureaucrat default Constructor
		// Bureaucrat bur;

		// Exceptions in constructor
		// Bureaucrat bur("Administrator", 0);
		// Bureaucrat bur("Administrator", 151);
		std::cout << bur << std::endl;

		bur.increaseGrade();
		std::cout << bur << std::endl;

		bur.setGrade(1);
		std::cout << bur << std::endl;

		// Exception while INcreasing
		// bur.increaseGrade();
		// std::cout << bur << std::endl;

		bur.setGrade(149);
		std::cout << bur << std::endl;

		bur.decreaseGrade();
		std::cout << bur << std::endl;

		// Exception while DEcreasing
		// bur.decreaseGrade();
		// std::cout << bur << std::endl;

		/***
		 *
		 * Form Test
		 *
		 ***/
		// Exception in constructor
		// Form formular("FormularEx01", 0, 25);
		// Form formular("FormularEx01", 1, 0);
		// Form formular("FormularEx01", 151, 1);
		// Form formular("FormularEx01", 1, 151);

		// Default constructor
		// Form formular;

		// Form Constructor
		Form formular("FormularEx01", 15, 25);

		try
		{
			// Exception no-sign formular
			//bur.signForm(formular);

			bur.setGrade(10);
			bur.signForm(formular);
		}
		catch (const Bureaucrat::NoSignException &e)
		{
			std::cout << RED << bur << " couldn’t sign " << formular << " because " << e.what() << WHITE << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << WHITE << std::endl;
	}
	return 0;
}
