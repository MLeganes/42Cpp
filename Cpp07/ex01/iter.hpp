#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*funct)(T &elemt))
{
	for(size_t i = 0; i < len; i++)
	{
		(*funct)(array[i]);
	}
}

template <typename T>
void iterPrint(T &elemt)
{
	std::cout << " [" << elemt << "] " ;
}

#endif