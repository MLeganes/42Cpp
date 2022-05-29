#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name) : weapon(NULL), name(name) {}
// HumanA::HumanA(const std::string &name) {
// 	//HumanA::name = name;
// 	//this->name = name;
// 	HumanA::setWeapon(weapon);
// }

void HumanB::attack(){
	std::cout << this->name << " atacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	//this->weapon = weapon;
	HumanB::weapon = &weapon;
}
