#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	std::string names[4];
	AMateria *materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria *createMateria(const std::string &type);

	MateriaSource &operator=(const MateriaSource &);
};

#endif
