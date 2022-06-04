#include "DiamondTrap.hpp"

// Constructors and Destructor.
DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
	this->_name = copy._name;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	
	// error: base class ‘class FragTrap’ should be explicitly initialized in the copy constructor
	// DiamondTrap::_name = name; 
	// Solution:
	DiamondTrap::_name = name; 
}
DiamondTrap::~DiamondTrap()
{}

// Overload Member functions
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap " << this->_name << " assignment operator= called" << std::endl;
	this->_name = copy._name;
	ClapTrap::operator=(copy);
	return *this;
}

// Member functions
void 	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << DiamondTrap::_name << " or " << ClapTrap::_name << std::endl;
}

std::string &DiamondTrap::getName()
{
	return this->_name;
}