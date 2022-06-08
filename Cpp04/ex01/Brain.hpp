#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#define MAXIDEAS 100

class Brain
{
private:
	std::string _ideas[MAXIDEAS];

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &);

	void				setIdea(unsigned int idx, const std::string &type);
	const std::string	&getIdea(unsigned int idx) const;
};

#endif