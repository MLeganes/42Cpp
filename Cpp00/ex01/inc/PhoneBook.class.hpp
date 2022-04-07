#include "Contact.class.hpp"

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

class PhoneBook {
private:
  int _ncontacts;
  Contact _contacts[8];

public:
  PhoneBook(void);
  ~PhoneBook(void);

  void add(void);
  void search(void);
  void setNContacts(int n);
  void increaseNContacts(void);
  int getNContacts(void);
  void printPreview(void);
  void printContact(int idx);
};

#endif