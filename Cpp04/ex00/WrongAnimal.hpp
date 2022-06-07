#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &wronganimal);

	// No virtual -- no call the inherit memeber funct.
	void makeSound() const;

	void setType(const std::string &type);
	const std::string &getType() const;
};

#endif