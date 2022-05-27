
#include <string>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA
{
private:
	Weapon &weapon;
	const std::string name;
public:
	HumanA(const std::string &name, Weapon &weapon);
	//~HumanA();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif