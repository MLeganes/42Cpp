#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	AMateria(const AMateria &);
	AMateria(const std::string &type);
	virtual ~AMateria();

	const std::string &getType() const;

	virtual AMateria *clone() const = 0;	// Pure Virtual
	virtual void use(ICharacter &target);	// Virtual

	AMateria &operator=(const AMateria &);
};

#endif
