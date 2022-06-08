#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "AAnimal";
	std::cout << "AAnimal default constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal &copy)
{
	this->_type = copy.getType();
	std::cout << "AAnimal " << this->_type << " copy constructor called" << std::endl;
}
AAnimal::AAnimal(const std::string &type)
{
	this->_type = type;
	std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->_type << " destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	this->_type = animal.getType();
	std::cout << "AAnimal " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal " << this->_type << " basic-class can NOT make sound! " << std::endl;
}

void AAnimal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string &AAnimal::getType() const
{
	return (this->_type);
}