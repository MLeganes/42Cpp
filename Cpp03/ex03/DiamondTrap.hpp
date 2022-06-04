#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	// Constructors and Destructor.
	DiamondTrap();
	DiamondTrap(const DiamondTrap &);
	DiamondTrap(const std::string &);
	~DiamondTrap();

	// Overload Member functions
	DiamondTrap	&operator=(const DiamondTrap &);

	// Member functions
	void 	attack(const std::string &target);
	void 	whoAmI();
	std::string &getName();


};

#endif
