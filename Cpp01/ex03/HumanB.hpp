
#include <string>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP
/***
 * 
 *  error: [-Werror=reorder]
 * Other answers have provided some good examples that justify the option for a warning.
 * I thought I'd provide some historical context. The creator of C++, Bjarne Stroustrup,
 * explains in his book The C++ programming language (3rd edition, Page 259):
    // The members’ constructors are called before the body of the containing class’ own 
	// constructor is executed. The constructors are called in the order in which they are
	// declared in the class rather than the order in which they appear in the initializer list. 
	// To avoid confusion, it is best to specify the initializers in declaration order. 
	// The member destructors are called in the reverse order of construction.
 * 
 * 
 ***/
class HumanB
{
private:
	Weapon *weapon;
	const std::string name;

public:
	HumanB(const std::string name);
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif