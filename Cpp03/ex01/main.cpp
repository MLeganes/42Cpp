
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {

	ClapTrap ctrap("#1");
	ScavTrap strap("#2");

	// ClapTrap ctrap("###The-Empire-Strikes-Back");
	// ScavTrap strap("***Return-of-the-Jedi");

	ctrap.setAttackDamage(5);
	ctrap.attack(strap.getName());
	
	strap.takeDamage(ctrap.getAttackDamage());
	strap.beRepaired(5);
	strap.setAttackDamage(11);
	strap.attack(ctrap.getName());

	ctrap.takeDamage(strap.getAttackDamage());	
	return (0);
}