#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
private:
	bool _gate;
public:
	// Constructors and Destructor.
	ScavTrap();
	ScavTrap(const ScavTrap &);
	ScavTrap(const std::string &);
	~ScavTrap();

	// Overload Member functions
	ScavTrap &operator=(const ScavTrap &);

	// Member functions
	void attack(const std::string &target);
	void guardGate();
};

#endif
