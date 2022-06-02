#include "ClapTrap.hpp"

// Constructors and Destructor.
ClapTrap::ClapTrap() : _attackDamage(0), _energyPoints(10), _hitPoints(10), _name() 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _attackDamage(0), _energyPoints(10), _hitPoints(10), _name(name) 
{
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
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
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy){}

// Member functions
void		ClapTrap::attack(const std::string &target){}
void		ClapTrap::takeDamage(unsigned int amount){}
void		ClapTrap::beRepaired(unsigned int amount){}

void		ClapTrap::setName(const std::string &name){}
void		ClapTrap::setHitPoints(unsigned int hitPoints){}
void		ClapTrap::setEnergyPoints(unsigned int energyPoints){}
void		ClapTrap::setAttackDamage(unsigned int attackDamage){}

const std::string	&ClapTrap::getName() const{}
unsigned int		ClapTrap::getHitPoints() const{}
unsigned int		ClapTrap::getEnergyPoints() const{}
unsigned int		ClapTrap::getAttackDamage() const{}