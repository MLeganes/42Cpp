#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &)
{
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"};
	int i;
	for (i = 0; i < 3; ++i)
	{
		if (forms[i] == name)
			break;
	}
	switch (i)
	{
	case 0:
		return new PresidentialPardonForm(target);
	case 1:
		return new RobotomyRequestForm(target);
	case 2:
		return new ShrubberyCreationForm(target);
	default:
		std::cerr << "Intern could not create form!" << std::endl;
		return 0L;
	}
}
