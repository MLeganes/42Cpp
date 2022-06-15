#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>

#include "AForm.hpp"

/***
 * ShrubberyCreationForm: Required grades: sign 145, exec 137
 * Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
 *
 ***/
class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	void				setTarget(const std::string &target);
	const std::string	getTarget() const;

	void execute(const Bureaucrat &executor) const;
};

#endif
