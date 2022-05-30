#include <string>
#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
private:
	std::string type;

public:
	Weapon(void);
	~Weapon(void);
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &type);
};

#endif
