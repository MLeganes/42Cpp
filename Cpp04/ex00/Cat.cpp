#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy)
{

	std::cout << "Cat " << this->_type << " copy constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat " << this->_type << " destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	this->_type = cat.getType();
	std::cout << "Cat " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meow meow meow!!!" << std::endl;
}