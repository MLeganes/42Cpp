#include "Contact.class.hpp"

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

class Phonebook{
private:
	Contact _contacts[10];
public:
	void add(Contact contact);
	void search(Contact contact);
};

#endif