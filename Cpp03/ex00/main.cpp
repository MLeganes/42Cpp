
#include <iostream>
#include "ClapTrap.hpp"


int main() {

	ClapTrap clap1("Zippi");
	ClapTrap clap2("Zappe");

	clap1.setAttackDamage(5);
	clap1.attack(clap2.getName());
	
	clap2.takeDamage(clap1.getAttackDamage());
	clap2.beRepaired(2);
	clap2.setAttackDamage(1);
	clap2.attack(clap1.getName());

	clap1.takeDamage(clap2.getAttackDamage());	
	return (0);
}