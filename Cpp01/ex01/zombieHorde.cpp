#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	// This is the way to allowate the N zombies.
	Zombie *zmbs = new Zombie[N]();

	for (int i = 0; i < N; i++)
		zmbs[i].setName(name);
	return (zmbs);
}
