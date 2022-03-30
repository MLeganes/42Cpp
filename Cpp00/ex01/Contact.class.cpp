#include <iostream>

#include "Contact.class.hpp"

Contact::Contact() {
    std::cout << "Default constructor from Contact has been called." << std::endl;
    return;
}
Contact::~Contact(void) {
    std::cout << "Default de-constructor from Contact has been called." << std::endl;
    return;
}
Contact::Contact(std::string first_name, std::string last_name, std::string phone) {
    this -> _first_name = first_name;
    this -> _last_name = last_name;
    this -> _phone = phone;
}

std::string Contact::getFirstName(void) {
    return (this -> _first_name);
}
std::string Contact::getLastName(void) {
    return this -> _last_name;
}
std::string Contact::getPhone(void) {
    return this -> _phone;
}
void Contact::setFirstName(std::string first_name) {
    this -> _first_name = first_name;
}
void Contact::setLastName(std::string last_name) {
    this -> _last_name = last_name;
}
void Contact::setPhone(int phone) {
    this -> _phone = phone;
}