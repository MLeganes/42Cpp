
#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
		harl.complain(" ");
	harl.complain(argv[1]);
	return (0);
}
