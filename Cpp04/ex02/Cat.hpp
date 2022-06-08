#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &cat);

	void				makeSound() const;
	void				setIdea(unsigned int idx, const std::string &idea);
	const std::string	&getIdea(unsigned int idx) const;
	Brain				*getBrain() const;

};

#endif