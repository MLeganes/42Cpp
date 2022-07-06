#ifndef SPAN_HPP
#define SPAN_HPP

// #include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

//class Span : public std::vector<int>
class Span 
{
private:
	std::vector<int>	_ivector;
	unsigned int		_size;
	// unsigned int		_idx;
	static int 			randomNumber();
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();

	Span &operator=(const Span &obj);

	std::vector<int>::iterator 	begin();
	std::vector<int>::iterator 	end();
	void						addNumber(int nbr);
	int 						shortestSpan();
	int 						longestSpan();
	void 						fillRandom();
	void						printVector();
};

#endif