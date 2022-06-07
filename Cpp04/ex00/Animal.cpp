#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal &copy)
{
	this->_type = copy.getType();
	std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
}
Animal::Animal(const std::string &type)
{
	this->_type = type;
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	this->_type = animal.getType();
	std::cout << "Animal " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal " << this->_type << " basic-class can NOT make sound! " << std::endl;
}

void Animal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string &Animal::getType() const
{
	return (this->_type);
}