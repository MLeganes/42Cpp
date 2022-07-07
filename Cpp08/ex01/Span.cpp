#include "Span.hpp"

// static void print(int n);

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &copy) : _size(copy.getSize())
{
	this->_ivector = copy.getVector();
}

Span::~Span() {}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->_size = obj.getSize();
		this->_ivector = obj.getVector();	
	}
	return (*this);
}

unsigned int Span::getSize() const
{
	return (this->_size);
}

const std::vector<int>	&Span::getVector() const
{
	return (this->_ivector);
}

std::vector<int>::iterator 	Span::begin()
{
	return this->_ivector.begin();
}

std::vector<int>::iterator 	Span::end()
{
	return this->_ivector.end();
}

void	Span::addNumber(int nbr)
{
	if (this->_ivector.size() < this->_size)
		this->_ivector.push_back(nbr);
	else
		throw std::out_of_range("error:span: Elements out of range");
}

int	Span::shortestSpan()
{
	if (this->_ivector.size() < 2)
		throw std::logic_error("error:span: No elements to get shortest span");
	
	long shortspan = std::numeric_limits<int>::max();	//max 2147483647, min -2147483648
	std::vector<int> tmp_ivec(this->_ivector);
	std::sort(tmp_ivec.begin(), tmp_ivec.end());
	for (unsigned long i = 0; i < tmp_ivec.size(); i++)
	{
		if (i + 1 < tmp_ivec.size())
		{
			if (tmp_ivec[i + 1] - tmp_ivec[i] < shortspan)
				shortspan = tmp_ivec[i + 1] - tmp_ivec[i];
		}
	}
	return shortspan;
}

int Span::longestSpan()
{
	int min = -1;
	int max = -1;

	if (this->_ivector.size() < 2)
		throw std::logic_error("error:span: No elements to get longest span");
	else
	{
		min = *std::min_element(this->_ivector.begin(), this->_ivector.end());
		max = *std::max_element(this->_ivector.begin(), this->_ivector.end());
	}
	return(static_cast<int>(max - min));
}

void 	Span::fillRandom()
{
	for (size_t i = 0; i < this->_size; i++)
	{
		this->addNumber(arc4random() % 2147483647);
	}
}

void Span::printVector()
{
	if (this->_ivector.size() == 0)
		std::cout << "Vector size is 0, nothing to print" << std::endl;
	else
	{
		//for_each(this->begin(), this->end(), print);
		int i = this->_ivector.size();
		for(;i >= 0; i--)
		{
			std::cout << this->_ivector[i] << " ";
		}
	}
}

// static void print(int n)
// {
// 	std::cout << n << " ";
// }
