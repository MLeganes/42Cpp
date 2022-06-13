#include "Bureaucrat.hpp"
#include <unistd.h>

int main()
{
	Bureaucrat bure1("Skywalker", 3);

	try
	{
		std::cout << bure1 << std::endl;

		bure1.setGrade(10);
		std::cout << bure1 << std::endl;

		// error
		bure1.setGrade(1);
		std::cout << bure1 << std::endl;
		bure1.increaseGrade();

		// error
		// bure1.setGrade(150);
		// std::cout << bure1 << std::endl;
		// bure1.decreaseGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
