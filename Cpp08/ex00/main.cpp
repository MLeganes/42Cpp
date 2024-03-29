#include "easyfind.hpp"

#include <iostream>
#include <algorithm>

#include <iterator>
#include <vector>
#include <map>
#include <list>

#define MAX_NBR 100

static int randomNumber();
static void printNumber(int &nbr);

int main()
{
	std::vector<int> 	ivector(MAX_NBR);
	std::list<int>		ilist(MAX_NBR);

	std::generate(ivector.begin(), ivector.end(), randomNumber);
	std::generate(ilist.begin(), ilist.end(), randomNumber);

	for_each(ivector.begin(), ivector.end(), printNumber);
		std::cout << std::endl;


// #1.
	try
	{
		std::vector<int>::iterator iter = easyfind(ivector, 11);
		std::cout << std::endl << "Found argument " << *(iter.base()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

// #2.
	ivector.push_back(42);
	try
	{
		std::vector<int>::iterator iter = easyfind(ivector, 42);
		std::cout << std::endl << "Found argument " << *(iter.base()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

// #3.
	try
	{
		std::vector<int>::iterator iter = easyfind(ivector, 4242);
		std::cout << std::endl << "Found argument " << *(iter.base()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for_each(ilist.begin(), ilist.end(), printNumber);
		std::cout << std::endl;

// #4.
	try
	{
		std::list<int>::iterator iter = easyfind(ilist, 11);
		std::cout << std::endl << "Found argument " << *(iter) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

// #5.
	ilist.push_back(42);
	try
	{
		std::list<int>::iterator iter = easyfind(ilist, 42);
		std::cout << std::endl << "Found argument " << *(iter) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

// #6.
	try
	{
		std::list<int>::iterator iter = easyfind(ilist, 4242);
		std::cout << std::endl << "Found argument " << *(iter) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}

static int randomNumber()
{
	return (random() % MAX_NBR);
}

static void printNumber(int &nbr)
{
	std::cout << nbr << " ";
}