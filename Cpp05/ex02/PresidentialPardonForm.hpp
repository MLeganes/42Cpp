#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <fstream>

#include "AForm.hpp"

/***
 * PresidentialPardonForm: Required grades: sign 25, exec 5
 * 
 *
 ***/
class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	void				setTarget(const std::string &target);
	const std::string	getTarget() const;

	void execute(const Bureaucrat &executor) const;
};

#endif
