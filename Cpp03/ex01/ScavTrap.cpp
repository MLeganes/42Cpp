#include "ScavTrap.hpp"

// Constructors and Destructor.
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << "copy constructor called" << std::endl;

}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

// Overload Member functions
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	ClapTrap::operator=(copy);
	std::cout << "ScavTrap " << this->_name << " assigment operator called" << std::endl;
	return (*this);
}

// Member functions
void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout 	<< "ScavTrap " << this->_name << " attacks " << target << " causing " <<  this->_attackDamage << " points of damage! " << std::endl;
	}
	else
	{
		std::cout 	<< "ScavTrap " << this->_name << " can NOT attacks!" << std::endl;
	}

}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
