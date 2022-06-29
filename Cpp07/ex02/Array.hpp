#ifndef ARRAY_HPP
#define ARRAY_HPP


/***
 * 
 *  Class-Template.
 * 
 ***/

template <class T>
class Array
{
private:
	T				*_array;
	unsigned int 	_size;

public:
	Array();
	Array(unsigned int size);
	Array(Array const &copy);
	~Array();

	Array	&operator=(Array<T> const &copy);
	T		&operator[](unsigned int index);

	unsigned int size() const;
};

#include "Array.tpp"

#endif
