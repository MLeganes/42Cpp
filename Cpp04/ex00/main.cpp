
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	std::cout << "1._Example with basic Animal class" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "Get type of animal: " << meta->getType() << " " << std::endl;
	meta->makeSound();
	delete meta;
	
	std::cout << std::endl << "2._Example with dog inherits Animal class" << std::endl;
	const Animal* j = new Dog();
	std::cout << "Get type of animal: " << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
	
	std::cout << std::endl << "3._Example with cat inherits Animal class" << std::endl;
	const Animal* i = new Cat();
	std::cout << "Get type of animal: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	delete i;

	std::cout << std::endl << "4._Example with WrongAnimal basic class" << std::endl;
	const WrongAnimal * generic = new WrongAnimal();
	std::cout << "Get type of WrongAnimal: " << generic->getType() << " " << std::endl;
	generic->makeSound();
	delete generic;

	std::cout << std::endl << "5._Example with WrongCat inherits from WrongAnimal class" << std::endl;
	const WrongAnimal * cat = new WrongCat();
	std::cout << "Get type of WrongCat: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	delete cat;

	return 0;
}
