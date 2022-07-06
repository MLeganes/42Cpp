#include "Span.hpp"
#include <iostream>



int main()
{
	Span sp = Span(5);
	try
	{
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	//sp.printVector();

		std::cout << "Shortes span: " << sp.shortestSpan() << std::endl;
		//std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

