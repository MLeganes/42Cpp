#include "Span.hpp"

static void print(int n);

Span::Span()
{
	// this->_ivector = new std::vector<int>();
	// this->_idx = 0;
	this->_size = 0;
}

Span::Span(unsigned int N)
{
	this->_size = N;
	// this->_idx = 0;
}

Span::Span(const Span &copy)
{
	//this->_size = 0;
	*this = copy;
}

Span::~Span()
{
	// delete;
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		// if (this->_ivector.size() > 0)
		// 	delete this->_ivector;
		// this->_ivector.assign(obj.begin(), obj.end());
	(void) obj;
	}
	return (*this);
}

std::vector<int>::iterator 	Span::begin()
{
	return this->_ivector.begin();
}

std::vector<int>::iterator 	Span::end()
{
	return this->_ivector.end();
}

void						Span::addNumber(int nbr)
{
	if (this->_ivector.size() < this->_size)
		this->_ivector.push_back(nbr);
}

int 						Span::shortestSpan()
{
	if (this->_ivector.size() < 2)
		throw std::logic_error("error:span: No elements to get shortest span");
	
		// 2147483647,	-2147483648
	long shortspan = 2147483647; // std::numeric_limits<int>::max();
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
	// std::vector<int>::iterator iter;
	// std::vector<int>::iterator begin = this->begin();
	// std::vector<int>::iterator end = this->end();
	
	// //std::for_each(this->begin(), this->end(), Span::checkSpan);
	// iter = this->begin();
	// span = *iter - *begin;
	// ++begin;

	// for(; iter != end; ++iter)
	// {
	// 	std::cout << "iter " << *iter << " begin " << *begin << std::endl;
	// 	if ((*iter - *begin) < span)
	// 		span = *iter - *begin;
	// 	++begin;
	// }
	// std::cout << "Return shortes span: " << span << std::endl;
	return shortspan;
}

int 						Span::longestSpan()
{
	int min = -1;
	int max = -1;

	if (this->_ivector.size() < 2)
		throw std::logic_error("error:span: No elements to get longest span");
	else
	{
		min = *std::min_element(this->_ivector.begin(), this->_ivector.end());
		//std::cout << "longestSpan Min:" << min << std::endl; 
		max = *std::max_element(this->_ivector.begin(), this->_ivector.end());
		//std::cout << "longestSpan Max:" << max << std::endl; 
	}
	return(static_cast<int>(max - min));
}

void 						Span::fillRandom()
{
	std::generate(this->_ivector.begin(), this->_ivector.end(), randomNumber);
}

int Span::randomNumber()
{
	return (random() % 2147483647);
}

void Span::printVector()
{
	std::cout << "Vector size: " << this->_ivector.size() << std::endl;
	if (this->_ivector.size() == 0)
		std::cout << "Vector size is 0, nothing to print" << std::endl;
	else
	{
		int i = this->_ivector.size();
		for(;i >= 0; i--)
		{
			std::cout << this->_ivector[i] << " ";
		}
	}
		std::cout << "this is printing with function:" << std::endl;
		for_each(this->begin(), this->end(), print);
}

static void print(int n)
{
	std::cout << n << " ";
}