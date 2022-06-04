#include "ClapTrap.hpp"

// Constructors and Destructor.
ClapTrap::ClapTrap() :  _name(),  _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)  
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

// Overload Member functions
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	std::cout << "ClapTrap " << this->_name << " assigment operator called" << std::endl;
	return (*this);
}

// Member functions
void		ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		//std::cout 	<< "ClapTrap " << this->_name << " attacks " << target << " causing " <<  this->_attackDamage << " points of damage! " << std::endl;
		std::cout 	<< "ClapTrap " << this->_name << " attacks " << target << " causing " <<  this->getAttackDamage() << " points of damage! " << std::endl;
	}
	else
	{
		std::cout 	<< "ClapTrap " << this->_name << " can NOT attacks!" << std::endl;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	} else {
		std::cout << "ClapTrap " << this->_name << " cannot take " << amount << " points of damage!" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	} else {
		std::cout << "ClapTrap " << this->_name << " cannot be repaired anymore!" << std::endl;
	}
}

void		ClapTrap::setName(const std::string &name)
{
	std::cout << "ClapTrap " << name << " setName() called" << std::endl;
	this->_name = name;
}
void		ClapTrap::setHitPoints(unsigned int hitPoints)
{
	std::cout << "ClapTrap " << this->_name << " setHitPoints() called" << std::endl;
	this->_hitPoints = hitPoints;
}
void		ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	std::cout << "ClapTrap " << this->_name << " setEnergyPoints() called" << std::endl;
	this->_energyPoints = energyPoints;
}
void		ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " setAttackDamage() called" << std::endl;
	this->_attackDamage = attackDamage;
}

const std::string	&ClapTrap::getName() const
{
	//std::cout << "ClapTrap " << this->_name << " getName() called" << std::endl;
	return (this->_name);
}
unsigned int		ClapTrap::getHitPoints() const
{
	//std::cout << "ClapTrap " << this->_name << " getHitPoints() called" << std::endl;
	return (this->_hitPoints);
}
unsigned int		ClapTrap::getEnergyPoints() const
{
	//std::cout << "ClapTrap " << this->_name << " getEnergyPoints() called" << std::endl;
	return (this->_energyPoints);
}
unsigned int		ClapTrap::getAttackDamage() const
{
	std::cout << "ClapTrap " << this->_name << " getAttackDamage() called" << std::endl;
	return (this->_attackDamage);
}