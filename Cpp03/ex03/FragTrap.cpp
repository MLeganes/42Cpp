#include "FragTrap.hpp"

// Constructors and Destructor.
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
}

// Copy constructors.
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << "copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

// Overload Member functions
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	ClapTrap::operator=(copy);
	std::cout << "FragTrap " << this->_name << " assigment operator called" << std::endl;
	return (*this);
}

// Member functions
void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints)
	{
		std::cout << "FragTrap " << this->_name << " Have five guys ✋!!!" << std::endl;
		this->_energyPoints--;
	}
}