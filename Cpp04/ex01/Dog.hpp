#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &dog);

	void				makeSound() const;
	void				setIdea(unsigned int idx, const std::string &idea);
	const std::string	&getIdea(unsigned int idx) const;
	Brain				*getBrain() const;
};

#endif