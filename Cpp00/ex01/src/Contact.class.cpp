#include <iostream>

#include "../inc/Contact.class.hpp"

Contact::Contact() { return; }
Contact::~Contact(void) { return; }
Contact::Contact(std::string first_name, std::string last_name,
                 std::string nick, std::string phone) {
  this->_first_name = first_name;
  this->_last_name = last_name;
  this->_phone = phone;
  this->_nick = nick;
}

std::string Contact::getFirstName(void) { return (this->_first_name); }
std::string Contact::getLastName(void) { return this->_last_name; }
std::string Contact::getNick(void) { return this->_nick; }
std::string Contact::getPhone(void) { return this->_phone; }

void Contact::setFirstName(std::string first_name) {
  this->_first_name = first_name;
}
void Contact::setLastName(std::string last_name) {
  this->_last_name = last_name;
}
void Contact::setNick(std::string nick) { this->_nick = nick; }
void Contact::setPhone(std::string phone) { this->_phone = phone; }
