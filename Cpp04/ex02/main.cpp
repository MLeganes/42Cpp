
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>

#define MAXANIMALS 10
#define MAXIDEAS 100

int main()
{
	AAnimal *animals[MAXANIMALS];

	int i = 0;
	for(;i < (MAXANIMALS / 2); i++)
	{
		animals[i] = new Dog();
		std::cout << "Dog #" << i << " created " << std::endl;
		for(int j = 0; j < MAXIDEAS; j++)
		{
			((Dog *) (animals[i]))->setIdea((unsigned int)j, "Dog idea ");
			std::cout << "------------------ " << ((Dog *) (animals[i]))->getIdea((unsigned int) j) << j << std::endl;
		}
	}
	for(;i < MAXANIMALS; i++)
	{
		animals[i] = new Cat();
		std::cout << "Cat #" << i << " created " << std::endl;
		for(int j = 0; j < MAXIDEAS; j++)
		{
			((Dog *) (animals[i]))->setIdea((unsigned int)j, "Cat idea ");
			std::cout << "------------------ " << ((Cat *) (animals[i]))->getIdea((unsigned int) j) << j << std::endl;
		}
	}

	AAnimal *dog = new Dog(*(Dog *)animals[0]);
	((Dog *)dog)->setIdea(0, " This a dog idea! ");
	((Dog *)dog)->setIdea(1, " This a dog idea! ");

	for (int x = 0; x < MAXIDEAS; x++)
	{
		std::cout << "---------------Type " << ((Dog *)dog)->getType() << ((Dog *)dog)->getIdea(x) << x << std::endl;
	}

	std::cout << std::endl << "---------------Delete dog-----------------" << std::endl;
	delete dog;

	std::cout << std::endl << "---------------Delete animal[]-----------------" << std::endl;
	while (i-- > 0)
		delete animals[i];
	
	return 0;
}
