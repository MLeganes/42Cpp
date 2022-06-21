
#include <unistd.h>
#include <iostream>

#include "Converter.hpp"

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

int main(int argc, char *argv[])
{
	
	if (argc != 2)
	{
		std::cout << "error: 1 argument input needed for conversion, char, int, float or double. Example: ./converter 42" << std::endl;
		return 1;
	}
	std::cout << "input parameter: " << argv[1] << std::endl;
	
	Converter cvt(argv[1]);


try
{
	/* code */
	std::cout << "char: " << cvt.convertToChar() << std::endl;

	std::cout << "int: " << cvt.convertToInt() << std::endl;
	std::cout << "float: " << cvt.convertToFloat() << std::endl;
	std::cout << "double: " << cvt.convertToDouble() << std::endl;

}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}


	return 0;
}
