#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &copy);
	Animal(const std::string &type);
	virtual ~Animal();

	Animal &operator=(const Animal &animal);

	virtual void				makeSound() const;
			void				setType(const std::string &type);
			const std::string	&getType() const;
};

#endif