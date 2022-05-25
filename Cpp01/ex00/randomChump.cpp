#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie *zmb;
	zmb = new Zombie(name);
	zmb->announce();
	delete zmb;
}