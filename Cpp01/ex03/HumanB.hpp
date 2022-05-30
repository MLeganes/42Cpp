#include "Weapon.hpp"
#include <string>

#ifndef HUMANB_HPP
#define HUMANB_HPP

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
