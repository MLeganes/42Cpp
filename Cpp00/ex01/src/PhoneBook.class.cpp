#include <iostream>
#include "../inc/PhoneBook.class.hpp"
#include "../inc/number.hpp"

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
	if (this->ncontacts < 7)
		this->ncontacts++;
}



void PhoneBook::add(){
	std::string opt;
	int 		index;
	bool		isnb;
	int 		i;

	index = this->getNContacts();
	do
	{
		std::cout << "Contact first name:" << std::endl;
		std::cout << "_> ";
		std::getline(std::cin, opt);
		this->contacts[index].setFirstName(opt);
	} while (opt.empty());
	opt.erase();

	do
	{
		std::cout << "Contact last name:" << std::endl;
		std::cout << "_> ";
		std::getline(std::cin, opt);
		this->contacts[index].setLastName(opt);
	} while (opt.empty());
	opt.clear();
	do
	{
		isnb = false;
		std::cout << "Contact phone:" << std::endl;
		std::cout << "_> ";
		std::getline(std::cin, opt);
		i = 0;
		while ( i < (int)opt.length()){
			if (isdigit(opt[i]) == false){
				isnb = false;
				break;
			}
			i++;
		}


		if (isnumber(opt) == false){
			std::cout << "Only numbers in phone" << std::endl;
			std::cout << "_> ";
			isnb = false;
		}else{
			isnb = true;
			std::cout << "Good numbers phone!!!!" << std::endl;
			std::getline(std::cin, opt);
			this->contacts[index].setPhone(opt);
		}
	} while (opt.empty() || isnb == false);
		
	
	std::cout << "\n### Phone Book: new contact added ###" << std::endl;
	std::cout << "Name  " << this->contacts[index].getFirstName()  << std::endl;
	std::cout << "Last  " << this->contacts[index].getLastName()  << std::endl;
	std::cout << "Phone " << this->contacts[index].getPhone()  << std::endl;

	this->increaseNContacts();
}

void PhoneBook::search(){
	std::string opt;
	int index;

	std::cout << "" << std::endl;
	std::cout << "_> ";
	std::getline(std::cin, opt);
	index = 0;
	while ( index < this->ncontacts)
	{
		if (this->contacts[index].getFirstName() == opt || this->contacts[index].getLastName() == opt){
			//print contact
		}
		
		index++;
	}
	
	return ;
}
