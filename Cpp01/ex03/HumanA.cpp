#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : weapon(weapon), name(name) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->name << " atacks with their " << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	// this->weapon = weapon;
	HumanA::weapon = weapon;
}
