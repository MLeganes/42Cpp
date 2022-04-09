/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:49:39 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 17:05:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "number.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void) {
  this->_ncontacts = 0;
  this->_index = 0;
  this->_full = false;
  return;
}

PhoneBook::~PhoneBook(void) { return; }

// int PhoneBook::getNContacts(void) { return this->_ncontacts; }

// void PhoneBook::increaseNContacts() {
//   this->_ncontacts++;
//   if (this->_ncontacts == 7) {
//   }
//   this->_ncontacts = 7;

//   std::cout << "\nIncreased contact-number " << this->_ncontacts <<
//   std::endl;
// }

void PhoneBook::add() {
  std::string opt;
  bool isnb;

  do {
    std::cout << "\nContact first name: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    this->_contacts[this->_index].setFirstName(opt);
  } while (opt.empty());
  opt.clear();
  do {
    std::cout << "Contact last name: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    this->_contacts[this->_index].setLastName(opt);
  } while (opt.empty());
  opt.clear();
  do {
    std::cout << "Contact nick name: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    this->_contacts[this->_index].setNick(opt);
  } while (opt.empty());
  opt.clear();

  do {
    isnb = false;
    std::cout << "Contact phone: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    if (isnumber(opt) == false) {
      std::cout << "\nError: Only numbers in phone-number, try it again!"
                << std::endl;
      isnb = false;
      opt.clear();
    } else if (opt.empty()) {
      opt.clear();
      isnb = false;
    } else {
      isnb = true;
      this->_contacts[this->_index].setPhone(opt);
    }
    opt.clear();
  } while (isnb == false);

  do {
    std::cout << "Contact darkest secret: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    this->_contacts[this->_index].setSecret(opt);
  } while (opt.empty());
  opt.clear();

  if (this->_full == false)
    this->_ncontacts++;
  if (this->_ncontacts == 8)
    this->_full = true;
    
  if (this->_index == 7) {
    this->_index = 0;
  } else {
    this->_index++; // index ready to add next contact.
  }

  std::cout << "\nPhonebook: new contact added" << std::endl;
}

void PhoneBook::search() {
  std::string opt;
  bool exit;
  int idx;

  if (this->printPreview() == 1)
    return;
  do {
    std::cout << "\nInsert index to display full contact: ";
    std::getline(std::cin, opt);
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    if (opt.empty() || isnumber(opt) == false) {
      std::cout << "\nError: Wrong index." << std::endl;
      exit = false;
    } else {
      idx = std::atoi(opt.c_str());
      if (idx < 1 || idx > 8) {
        exit = false;
        std::cout << "\nError: Index should be between 1 to 8." << std::endl;
      } else if (idx <= this->_ncontacts) {
        this->printContact(idx - 1);
        exit = true;
      } else {
        std::cout << "\nThis contact is empty in PhoneBook." << std::endl;
        exit = true;
      }
    }
    opt.clear();
  } while (exit == false);
  return;
}

int PhoneBook::printPreview(void) {
  if (this->_ncontacts == 0) {
    std::cout << "\nPhoneBook is empty!\n" << std::endl;
    return 1;
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
    return 0;
  }
}

void PhoneBook::printContact(int idx) {
  std::cout << std::left << std::setw(14)
            << "First name: " << this->_contacts[idx].getFirstName()
            << std::endl;
  std::cout << std::left << std::setw(14)
            << "Last name: " << this->_contacts[idx].getLastName() << std::endl;
  std::cout << std::left << std::setw(14)
            << "Nickname: " << this->_contacts[idx].getNick() << std::endl;
  std::cout << std::left << std::setw(14)
            << "Phone number: " << this->_contacts[idx].getPhone() << std::endl;
  std::cout << std::left << std::setw(14)
            << "Darkest secret: " << this->_contacts[idx].getSecret()
            << std::endl;
}
