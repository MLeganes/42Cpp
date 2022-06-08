#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type() {}

AMateria::AMateria(const AMateria &other) : type(other.getType()) {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const
{
	return AMateria::type;
}

void AMateria::use(ICharacter &)
{
	std::cout << "Nothing to be used here!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	type = other.getType();
	return *this;
}
