
#include <iostream>
#include "ClapTrap.hpp"
#include <stdlib.h>

void printGame(ClapTrap *robot[2], int id_atack, int id_take_d)
{
		//system("clear");
		std::cout << "|*******************************************|" << std::endl;
		std::cout << "|                  ClapTrap                 |" << std::endl;
		std::cout << "|*******************************************|\n" << std::endl;
		std::cout << WHITE"1. Attack   2. Be repaired\n" << std::endl;
		
		std::cout <<  robot[id_atack]->getName() << "\t" << robot[id_atack]->getHitPoints();
		std::cout <<  "\t" << robot[id_take_d]->getName() << "\t" << robot[id_take_d]->getHitPoints() << "\n" << std::endl;
		std::cout << GREEN <<  "Energy points: "<< robot[id_atack]->getEnergyPoints() << " > " << WHITE;
}

int main() {

	
	ClapTrap *clap[2];
	ClapTrap clap1("Han-Solo");
	ClapTrap clap2("Skywalker");

	clap[0] = &clap1;
	clap[1] = &clap2;

	clap1.setAttackDamage(3);
	clap2.setAttackDamage(3);

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
		
		default:
			break;
		}
		id_atack = ( id_atack == 0 ) ? 1 : 0;
		id_take_d = ( id_atack == 1 ) ? 0 : 1;

	}while (clap1.getHitPoints() > 0 && clap2.getHitPoints() > 0);

	return (0);
}