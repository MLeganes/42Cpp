#include "Bureaucrat.hpp"
#include <unistd.h>

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

int main()
{
	std::cout << GREEN << std::endl << " 1). Test " << WHITE << std::endl;
	try
	{
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
