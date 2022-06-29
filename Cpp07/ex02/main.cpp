#include <iostream>
#include <cstdlib>

#include "Array.hpp"


#define MAX_VAL 750
#define HERE std::cout << "here..." << std::endl;

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::cout << "error: No arguments needed" << std::endl;
		(void) argv;
		return 1;
	}
    Array<int> numbers(MAX_VAL); // Stack memory
	int* mirror = new int[MAX_VAL]; // Heap memory
    
	//srand(time(NULL));
    // Print the 
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		//std::cout << i << " Random for numbers: " << numbers[i] << " mirror: " << mirror[i] << std::endl;
    }


    //SCOPE
    {
		// 1). Example Constructor
		Array<int> tmp1;	// Array Default Constructor.
		tmp1 = numbers;		// operator=

		// 2). Example Constructor: Array COPY construtor
		//Array<int> tmp2 = numbers; // Array COPY construtor 

		// 3). Example Constructor: Array COPY construtor
		//Array<int> tmp3(numbers); 

		// 4). Example Constructor: Array COPY construtor
		Array<int> test(tmp1);

		for(unsigned int i = 0; i < tmp1.size(); i++)
		{
			if (tmp1[i] != test[i])
				std::cerr << "didn't save the same value!!" << std::endl;
		}
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}


	// # 1). Example Throw Exception: error: Array: Index is out of bounds
    // try
    // {
    //    numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
	// # 2). Example Throw Exception: error: Array: Index is out of bounds
	// try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		 //std::cout << i << " 2.Rand for: " << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}