#include <string>
#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
private:
	std::string type;
public:
	//Weapon();
	Weapon(const std::string &type);
	//~Weapon();
	const std::string &getType() const;
	void setType(const std::string &type);
};

#endif