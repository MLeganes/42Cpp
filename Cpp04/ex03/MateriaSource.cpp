#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : names(), materias() {}

MateriaSource::MateriaSource(const MateriaSource &other) : names(), materias()
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.materias[i] != 0L)
		{
			names[i] = other.materias[i]->getType();
			materias[i] = other.materias[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != 0L)
		{
			delete materias[i];
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (&other != this)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (materias[i] != 0L)
			{
				delete materias[i];
			}
			names[i] = "";
			materias[i] = 0L;
			if (other.materias[i] != 0L)
			{
				materias[i] = other.materias[i]->clone();
				names[i] = other.materias[i]->getType();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == 0L)
		{
			materias[i] = materia;
			names[i] = materia->getType();
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (names[i] == type)
		{
			return materias[i]->clone();
		}
	}
	return 0L;
}
