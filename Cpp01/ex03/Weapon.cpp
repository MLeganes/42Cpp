#include "Weapon.hpp"

Weapon::Weapon(void){}
Weapon::~Weapon(void){}
Weapon::Weapon(const std::string &type) : type(type){}

const std::string &Weapon::getType() const{
	return (this->type);
}

void Weapon::setType(const std::string &type){
	Weapon::type = type;
}
