#include "Bureaucrat.hpp"
#include <unistd.h>

int main()
{
	// try
	// {
	// 	Bureaucrat bure1("Skywalker", 3);
	// 	Form form1("form1", 15, 25);

	// 	std::cout << bure1 << std::endl;
	// 	bure1.setGrade(10);
	// 	std::cout << bure1 << std::endl;

	// 	// Form signed.
	// 	bure1.signForm(form1);

	// 	// Throw exception.
	// 	bure1.setGrade(20);
	// 	bure1.signForm(form1);

	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	Bureaucrat bure2("Skywalker2", 3);
	Form form2("form2", 15, 25);

	std::cout << bure2 << std::endl;
	bure2.setGrade(10);
	std::cout << bure2 << std::endl;

	// Form signed.
	bure2.signForm(form2);

	bure2.setGrade(60);
	std::cout << bure2 << std::endl;
	// Throw exception.
	bure2.signForm(form2);


	return 0;
}
