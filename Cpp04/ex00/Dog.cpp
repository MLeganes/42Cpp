#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy)
{

	std::cout << "Dog " << this->_type << " copy constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog " << this->_type << " destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	this->_type = dog.getType();
	std::cout << "Dog " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "ruff ruff ruff!!!" << std::endl;
}