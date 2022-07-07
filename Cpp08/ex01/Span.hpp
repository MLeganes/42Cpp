#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

class Span 
{
private:
	std::vector<int>	_ivector;
	unsigned int		_size;
	static int 			randomNumber();
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();

	Span &operator=(const Span &obj);

	unsigned int				getSize() const;
	const std::vector<int>		&getVector() const;
	std::vector<int>::iterator 	begin();
	std::vector<int>::iterator 	end();
	void						addNumber(int nbr);
	int 						shortestSpan();
	int 						longestSpan();
	void 						fillRandom();
	void						printVector();
};

#endif