#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain())
{
	this->_type = "Cat";

	// Other way to construct brain as well.
	// this->_brain = new Brain();
	
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : AAnimal(copy), _brain(new Brain(*copy.getBrain()))
{
	std::cout << "Cat " << this->_type << " copy constructor called" << std::endl;
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat " << this->_type << " destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->_type = cat.getType();
		delete this->_brain;
		this->_brain = new Brain(*cat.getBrain());
	}
	std::cout << "Cat " << this->_type << " assigment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meow meow meow!!!" << std::endl;
}

void Cat::setIdea(unsigned int idx, const std::string &idea)
{
	this->_brain->setIdea(idx, idea);
}

const std::string &Cat::getIdea(unsigned int idx) const
{
	return (this->_brain->getIdea(idx));
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}
