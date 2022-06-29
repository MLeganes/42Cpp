#include <iostream>
#include "iter.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::cout << "error: No arguments needed" << std::endl;
		(void) argv;
		return 1;
	}
	size_t len = 10;
	char arrChar[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int arrInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float arrFloat[] = {1.42f, 2.42f, 3.42f, 4.42f, 5.42f, 6.42f, 7.42f, 8.42f, 9.42f, 10.42f};
	double arrDouble[] = {1.42, 2.42, 3.42, 4.42, 5.42, 6.42, 7.42, 8.42, 9.42, 10.42};


	::iter(arrChar, len, &iterPrint);
	std::cout << std::endl;

	::iter(arrInt, len, &iterPrint);
	std::cout << std::endl;

	::iter(arrFloat, len, &iterPrint);
	std::cout << std::endl;
	
	::iter(arrDouble, len, &iterPrint);
	std::cout << std::endl;

	return 0;
}