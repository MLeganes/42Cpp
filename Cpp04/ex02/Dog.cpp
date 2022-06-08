#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	this->_type = "Dog";

	// One wat to construct brain as well.
	// this->_brain = new Brain();
	
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy), _brain(new Brain(*copy.getBrain()))
{
	std::cout << "Dog " << this->_type << " copy constructor called" << std::endl;
}
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog " << this->_type << " destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog.getType();
		delete this->_brain;
		this->_brain = new Brain(*dog.getBrain());
	}
	std::cout << "Dog " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "ruff ruff ruff!!!" << std::endl;
}

void Dog::setIdea(unsigned int idx, const std::string &idea)
{
	this->_brain->setIdea(idx, idea);
}

const std::string &Dog::getIdea(unsigned int idx) const
{
	return (this->_brain->getIdea(idx));
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}