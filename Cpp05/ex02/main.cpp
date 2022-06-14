#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

int main()
{

	try
	{
		Bureaucrat bur("Administrator", 100);
		std::cout << bur << std::endl;

		bur.increaseGrade();
		std::cout << bur << std::endl;

		bur.setGrade(1);
		std::cout << bur << std::endl;

		// Exception
		//bur.increaseGrade();
		//std::cout << bur << std::endl;

		bur.setGrade(149);
		std::cout << bur << std::endl;

		bur.decreaseGrade();
		std::cout << bur << std::endl;
		
		// Exception
		//bur.decreaseGrade();
		//std::cout << bur << std::endl;

		AForm form


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// std::cout << GREEN << std::endl << "1). Test ShrubberyCreationForm Sign-grade: 145 Execute-grade: 137" << WHITE << std::endl;
	// try
	// {
	// 	Bureaucrat bure("Administrator-bery", 100); //name, grade
	// 	ShrubberyCreationForm scf("form-bery"); // target-name
	// 	std::cout << scf << std::endl;
	// 	bure.setGrade(145); //To sign the form.
	// 	bure.signForm(scf);
	// 	scf.execute(bure); // Check new file with trees.
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }


	// std::cout << GREEN << std::endl << "2). Test RobotomyRequestForm" << WHITE << std::endl;
	// RobotomyRequestForm rrf("Robot", 10, 150);
	
	// Bureaucrat brrf("Andministrator2", 50);
	// brrf.setGrade(5);
	// brrf.signForm(rrf);
	// rrf.execute(brrf);

	 


	return 0;
}
