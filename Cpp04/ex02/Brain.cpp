#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < MAXIDEAS; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MAXIDEAS; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

void Brain::setIdea(unsigned int idx, const std::string &str)
{
	this->_ideas[idx] = str;
}

const std::string &Brain::getIdea(unsigned int idx) const
{
	return (this->_ideas[idx]);
}
