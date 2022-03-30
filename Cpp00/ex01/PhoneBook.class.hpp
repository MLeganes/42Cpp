#include "Contact.class.hpp"

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

class PhoneBook{
private:
	int ncontacts;
	Contact contacts[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add();
	//void search(Contact contact);
	void setNContacts(int n);
	void increaseNContacts(void);
	int getNContacts(void);
};

#endif