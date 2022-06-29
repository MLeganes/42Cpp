#include "Array.hpp"


/***
 * 
 *  Class-Template definition here.
 * 
 ***/

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Default Constructor" << std::endl;
	_size = 0;
	_array = NULL;
}

template <typename T> 
Array<T>::Array(unsigned int size)
{
	std::cout << "Array Size-Constructor" << std::endl;
	_array = new T[size];
	_size = size;
}

// Copy constructor.
template <typename T>
Array<T>::Array(Array<T> const &copy)
{
	std::cout << "Array Copy Constructor" << std::endl;
	this->_size = copy.size();
	this->_array = new T[copy.size()];
	for(unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->_size > 0)
		delete []this->_array;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &obj)
{
	std::cout << "Array operantor=" << std::endl;
	if (this != &obj)
	{
		if (this->_size > 0)
			delete [] this->_array;
		this->_size = obj.size();
		this->_array = new T[obj._size];
		for(unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = obj._array[i];
	}
	return (*this);
}

template <typename T>
T		&Array<T>::operator[](unsigned int index)
{
	if(index >= this->_size)
		throw std::out_of_range("error: Array: Index is out of bounds");
	return (this->_array[index]);
}

template <typename T>
unsigned int		Array<T>::size() const
{
	return (this->_size);
}
