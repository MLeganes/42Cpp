#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);

	Intern &operator=(const Intern &);
};

#endif
