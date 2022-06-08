#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal(const std::string &type);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &animal);

	virtual void				makeSound() const = 0;	// Pure Virtual Member Function, makes the Class Abstract.
			void				setType(const std::string &type);
			const std::string	&getType() const;
};

#endif