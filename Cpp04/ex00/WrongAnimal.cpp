#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->_type = copy.getType();
	std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
	this->_type = WrongAnimal.getType();
	std::cout << "WrongAnimal " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << this->_type << " basic-class can NOT make sound! " << std::endl;
}

void WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string &WrongAnimal::getType() const
{
	return (this->_type);
}