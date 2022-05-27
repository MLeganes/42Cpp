#include "Zombie.hpp"

void randomChump( std::string name ) {
	
	// 1. Memory reservation
	// Zombie *zmb;
	// zmb = new Zombie(name);
	// zmb->announce();
	//delete zmb;

	// 2. NO-Memory reservation
	Zombie zmb(name);
	zmb.announce();
}
