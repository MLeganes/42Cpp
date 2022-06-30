#include "Span.hpp"

	Span::Span()
	{
		this->_ivector = new std::vector<int>();
		this->_idx = 0;
		this->_size = 0;
	}

	Span::Span(unsigned int N)
	{
		this->_ivector = new std::vector<int>(N);
		this->_size = N;
		this->_idx = 0;
		if (this->_ivector == NULL)
			throw std::bad_alloc();
	}

	Span::Span(const Span &copy)
	{
		this->_size = 0;
		*this = copy;
	}

	Span::~Span()
	{
		delete this->_ivector;
	}

	Span &Span::operator=(const Span &obj)
	{
		if (this != &obj)
		{
			if (this->_ivector->size() > 0)
				delete this->_ivector;
			this->_ivector->assign(obj.begin(), obj.end());	
		}
		return (*this);
	}

	std::vector<int>::iterator 	Span::begin() const
	{
		return this->_ivector->begin();
	}

	std::vector<int>::iterator 	Span::end() const
	{
		return this->_ivector->end();
	}

	void						Span::addNumber(int nbr)
	{
		this->_ivector->push_back(nbr);
		this->_size = this->_ivector->size();
	}

	int 						Span::shortestSpand() const
	{
		return 11111;
	}

	int 						Span::longestSpand() const
	{
		return 222222;
	}

	void 						Span::fillRandom()
	{
		std::generate(this->_ivector->begin(), this->_ivector->end(), Span::randomNumber);
	}

	int Span::randomNumber()
	{
		return (random() % 2147483647);
	}