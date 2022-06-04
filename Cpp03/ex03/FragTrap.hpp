#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

// FragTrap class that inherits from ClapTrap
class FragTrap : public ClapTrap
{
private:
	
public:
	// Constructors and Destructor.
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(const std::string &name);
	~FragTrap();

	// Overload Member functions
	FragTrap &operator=(const FragTrap &copy);

	// Member functions
	void highFivesGuys(void);
};

#endif
