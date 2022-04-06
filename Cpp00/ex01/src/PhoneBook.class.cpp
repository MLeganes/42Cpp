#include <iostream>
#include <string>

#include "../inc/Contact.class.hpp"
#include "../inc/PhoneBook.class.hpp"
#include "../inc/number.hpp"

PhoneBook::PhoneBook(void) {
  this->_ncontacts = 0;
  return;
}

PhoneBook::~PhoneBook(void) { return; }

int PhoneBook::getNContacts(void) { return this->_ncontacts; }
void PhoneBook::increaseNContacts() {
  if (this->_ncontacts < 7)
    this->_ncontacts++;
}

void PhoneBook::add() {
  std::string opt;
  int index;
  bool isnb;

  index = this->getNContacts();
  do {
    std::cout << "\nContact first name:" << std::endl;
    std::cout << "_> ";
    std::getline(std::cin, opt);
    this->_contacts[index].setFirstName(opt);
  } while (opt.empty());
  opt.clear();

  do {
    std::cout << "Contact last name:" << std::endl;
    std::cout << "_> ";
    std::getline(std::cin, opt);
    this->_contacts[index].setLastName(opt);
  } while (opt.empty());
  opt.clear();
  do {
    isnb = false;
    std::cout << "Contact phone:" << std::endl;
    std::cout << "_> ";
    std::getline(std::cin, opt);

    if (isnumber(opt) == false) {
      std::cout << "Only numbers in phone-number, try it again." << std::endl;
      isnb = false;
    } else {
      isnb = true;
      this->_contacts[index].setPhone(opt);
    }
    opt.clear();
  } while (isnb == false);

  std::cout << "\nPhonebook: new contact added " << std::endl;
  std::cout << "First Name   " << this->_contacts[index].getFirstName()
            << std::endl;
  std::cout << "Last  Name   " << this->_contacts[index].getLastName()
            << std::endl;
  std::cout << "Phone number " << this->_contacts[index].getPhone()
            << std::endl;
  std::cout << "\n" << std::endl;

  this->increaseNContacts();
}

void PhoneBook::search() {
  std::string opt;
  bool exitWhile;
  int nb;

  this->printPreview();
  do {
    std::cout << "\nInsert index to display full contact:" << std::endl;
    std::cout << "_> ";
    std::getline(std::cin, opt);
    if (opt.empty() || isnumber(opt) == false){
      std::cout << "\nError: Wrong index" << std::endl;
      exitWhile = false;
    }else
    {
      exitWhile = true;
      nb = std::stoi(opt);
      this->printContact(nb -1);
    }

  } while (exitWhile == false);


  return;
}

void PhoneBook::printPreview(void) {
  if (this->_ncontacts == 0) {
    std::cout << "\nPhoneBook is empty!\n" << std::endl;
  } else {
    for (int i = 0; i < this->_ncontacts; i++) {
      std::cout << std::setw(10) << i + 1 << "|";
      if (this->_contacts[i].getFirstName().length() > 10)
        std::cout << std::setw(9)
                  << this->_contacts[i].getFirstName().substr(0, 9) << "."
                  << "|";
      else
        std::cout << std::setw(10) << this->_contacts[i].getFirstName() << "|";
      if (this->_contacts[i].getLastName().length() > 10)
        std::cout << std::setw(9)
                  << this->_contacts[i].getLastName().substr(0, 9) << "."
                  << "|";
      else
        std::cout << std::setw(10) << this->_contacts[i].getLastName() << "|";
      if (this->_contacts[i].getNick().length() > 10)
        std::cout << std::setw(9) << this->_contacts[i].getNick().substr(0, 9)
                  << "." << std::endl;
      else
        std::cout << std::setw(10) << this->_contacts[i].getNick() << std::endl;
    }
  }
}

void    PhoneBook::printContact(int idx)
{
    std::cout << std::left << std::setw(14) << "First name: " << this->_contacts[idx].getFirstName() << std::endl;
    std::cout << std::left << std::setw(14) << "Last name: " << this->_contacts[idx].getLastName() << std::endl;
    std::cout << std::left << std::setw(14) << "Nickname: " << this->_contacts[idx].getNick() << std::endl;
    std::cout << std::left << std::setw(14) << "Phone number: " << this->_contacts[idx].getPhone() << std::endl;
}
