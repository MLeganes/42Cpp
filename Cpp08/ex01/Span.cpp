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

	int 						Span::shortestSpan() const
	{
		unsigned int span = -1;

		if (this->_ivector->size() < 2)
			throw std::logic_error("error:span: No elements in span");
		std::vector<int>::iterator iter;
		std::vector<int>::iterator begin = this->begin();
		std::vector<int>::iterator end = this->end();
		std::sort(this->begin(), this->end());
		//std::for_each(this->begin(), this->end(), Span::checkSpan);
		 iter = begin;
		++begin;
		for(; iter != end; ++iter)
		{
			if ((*iter - *begin) < span)
				span = *iter - *begin;
			++begin;
		}
		return span;
	}

	int 						Span::longestSpan() const
	{
		int min;
		int max;

		if (this->_ivector->size() < 2)
			throw std::logic_error("error:span: No elements in span");
		else
		{
			min = *std::min_element(this->begin(), this->end());
			max = *std::max_element(this->begin(), this->end());
		}
		return(static_cast<int>(max - min));
	}

	void 						Span::fillRandom()
	{
		std::generate(this->_ivector->begin(), this->_ivector->end(), Span::randomNumber);
	}

	int Span::randomNumber()
	{
		return (random() % 2147483647);
	}