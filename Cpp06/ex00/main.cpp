
#include <unistd.h>
#include <iostream>

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

int main(int argc, char *argv[])
{
	
	if (argc != 2)
	{
		std::cout << "error: 2 arguments input. Example .//conver 42" << std::endl;
		return 1;
	}
	std::cout << "input parameter: " << argv[1] << std::endl;


	return 0;
}
