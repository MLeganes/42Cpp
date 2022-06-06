
#include <iostream>
#include <cstdio>
#include <stdlib.h>

#include "ScavTrap.hpp"
#include <stdlib.h>

void printGame(ScavTrap *robot[2], int id_atack, int id_take_d)
{
		//system("clear");
		std::cout << "|*******************************************|" << std::endl;
		std::cout << "|                  ScavTrap                 |" << std::endl;
		std::cout << "|*******************************************|\n" << std::endl;
		std::cout << WHITE"1. Attack   2. Be repaired   3. Gate keeper mode  \n" << std::endl;
		
		std::cout <<  robot[id_atack]->getName() << "\t" << robot[id_atack]->getHitPoints();
		std::cout <<  "\t" << robot[id_take_d]->getName() << "\t" << robot[id_take_d]->getHitPoints() << "\n" << std::endl;
		std::cout << GREEN <<  "Energy points: "<< robot[id_atack]->getEnergyPoints() << " > " << WHITE;
}

int main() {

	
	ScavTrap *clap[2];
	ScavTrap clap1("Han-Solo");
	ScavTrap clap2("Skywalker");

	clap[0] = &clap1;
	clap[1] = &clap2;

	std::string line;
	int opt;


	int id_atack = 0;
	int id_take_d = 1;
	do {
		printGame(clap, id_atack, id_take_d);
		std::getline(std::cin, line);
		if (std::cin.eof() == true)
			exit(0);
		
		opt = atoi(line.c_str());
		switch (opt)
		{
		case 1: // atack
			clap[id_atack]->attack(clap[id_take_d]->getName());
			clap[id_atack]->takeDamage(clap[id_atack]->getAttackDamage());
			break;

		case 2: // be repaired
			clap[id_atack]->beRepaired(5);
			break;
		
		case 3: // be repaired
			clap[id_atack]->guardGate();
			break;
		
		default:
			break;
		}
		id_atack = ( id_atack == 0 ) ? 1 : 0;
		id_take_d = ( id_atack == 1 ) ? 0 : 1;

	}while (clap1.getHitPoints() > 0 && clap2.getHitPoints() > 0);

	return (0);
}