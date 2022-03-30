#include <iostream>

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	this->ncontacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

int PhoneBook::getNContacts(void){
	return this->ncontacts;
}
void PhoneBook::increaseNContacts(){
	this->ncontacts++;
}

void PhoneBook::add(){
	std::string opt;
	int 		phone;
	int 		index;

	index = this->getNContacts();
	if (index >= 8)
		index = 8;
	
	std::cout << "Contact first name:" << std::endl;
	std::cout << "_> ";
	std::cin >> opt;
	this->contacts[index].setFirstName(opt);

	std::cout << "Contact last name:" << std::endl;
	std::cout << "_> ";
	std::cin >> opt;
	this->contacts[index].setLastName(opt);
	std::cout << "Contact phone:" << std::endl;
	std::cout << "_> ";
	std::cin >> phone;
	//if (isdigit(phone))
	this->contacts[index].setPhone(phone);
	std::cout << "\n### Phone Book: new contact added ###" << std::endl;
	std::cout << "Name  " << this->contacts[index].getFirstName()  << std::endl;
	std::cout << "Last  " << this->contacts[index].getLastName()  << std::endl;
	std::cout << "Phone " << this->contacts[index].getPhone()  << std::endl;
}

// void PhoneBook::search(Contact contact){
// }

