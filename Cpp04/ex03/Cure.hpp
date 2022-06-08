#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &);
	~Cure();

	AMateria *clone() const;

	void use(ICharacter &target);

	Cure &operator=(const Cure &);
};

#endif
