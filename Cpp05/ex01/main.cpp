#include "Bureaucrat.hpp"

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

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
		// Exceptions in constructor
		//Bureaucrat bur("Administrator", 0);
		//Bureaucrat bur("Administrator", 151);
		Bureaucrat bur("Administrator", 100);
		std::cout << bur << std::endl;

		bur.increaseGrade();
		std::cout << bur << std::endl;

		bur.setGrade(1);
		std::cout << bur << std::endl;

		// Exception while INcreasing
		//bur.increaseGrade();
		//std::cout << bur << std::endl;

		bur.setGrade(149);
		std::cout << bur << std::endl;

		bur.decreaseGrade();
		std::cout << bur << std::endl;
		
		// Exception while DEcreasing
		//bur.decreaseGrade();
		//std::cout << bur << std::endl;

		// Exception in constructor
		//Form form2("formular", 0, 25);
		//Form form2("formular", 1, 0);
		//Form form2("formular", 151, 1);
		//Form form2("formular", 1, 151);
		
		/***
		*
		* Form Test
		*
		***/
		// Default constructor
		//Form formular;

		// Constructor with parameters
		Form formular("FormularEx01", 15, 25);
		std::cout << formular << std::endl;
		
		// Exception no-sign formular
		bur.signForm(formular);

		bur.setGrade(10);
		std::cout << bur << std::endl;

		bur.signForm(formular);
		std::cout << formular << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
