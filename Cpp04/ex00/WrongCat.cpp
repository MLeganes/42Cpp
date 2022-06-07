#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{

	std::cout << "WrongCat " << this->_type << " copy constructor called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->_type << " destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	this->_type = wrongcat.getType();
	std::cout << "WrongCat " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong meow !!!" << std::endl;
}