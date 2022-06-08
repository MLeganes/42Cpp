#include "Character.hpp"

Character::Character() : name(), inventory() {}

Character::Character(const std::string &name) : name(name), inventory() {}

Character::Character(const Character &copy) : name(copy.getName()), inventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i] != 0L)
		{
			delete inventory[i];
			inventory[i] = copy.inventory[i]->clone();
		}
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != 0L)
		{
			delete inventory[i];
		}
	}
}

Character &Character::operator=(const Character &copy)
{
	if (&copy != this)
	{
		name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = copy.inventory[i]->clone();
		}
	}
	return *this;
}

const std::string &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == 0L)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		inventory[idx] = 0L;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		inventory[idx]->use(target);
	}
}
