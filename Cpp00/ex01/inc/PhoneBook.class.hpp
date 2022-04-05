#include "Contact.class.hpp"
#include <iostream>

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

class PhoneBook{
private:
	int ncontacts;
	Contact contacts[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(void);
	void search(void);
	void setNContacts(int n);
	void increaseNContacts(void);
	int getNContacts(void);
};

#endif