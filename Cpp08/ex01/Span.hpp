#ifndef SPAN_HPP
#define SPAN_HPP

// #include <iostream>
#include <algorithm>

#include <vector>
#include <stdexcept>

//class Span : public std::vector<int>
class Span 
{
private:
	std::vector<int>	*_ivector;
	unsigned int		_size;
	unsigned int		_idx;
	static int 			randomNumber();
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();

	Span &operator=(const Span &obj);

	std::vector<int>::iterator 	begin() const;
	std::vector<int>::iterator 	end() const;
	void						addNumber(int nbr);
	int 						shortestSpand() const;
	int 						longestSpand() const;
	void 						fillRandom();

};

#endif