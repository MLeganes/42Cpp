#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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