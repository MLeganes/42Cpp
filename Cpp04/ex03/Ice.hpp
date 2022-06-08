#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &);
	~Ice();

	void use(ICharacter &target);

	AMateria *clone() const;

	Ice &operator=(const Ice &);
};

#endif
