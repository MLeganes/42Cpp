/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:40:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/03/30 16:06:04 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
	std::string opt;
	int exit;
	PhoneBook agenda;

	std::cout << "### Phone Book ###" << std::endl;
	exit = 1;
	while (exit)
	{
		//print menu
		std::cout << "Phone book options:" << std::endl;
		std::cout << " (A) Add new contact" << std::endl;
		std::cout << " (S) Search contact" << std::endl;
		std::cout << " (E) Exit phonebook" << std::endl;
		std::cout << "Select one option:" << std::endl;
		std::cout << "_> ";
		//std::cin >> opt;
		std::getline(std::cin, opt);

		//switch for the options
		if( opt == "a" || opt == "A" || opt == "add" || opt == "Add"){
			agenda.add();
			
		}
		else if ( opt == "s" || opt == "S" || opt == "search" || opt == "Search"){
			std::cout << "_> (S) option selected by " << opt << std::endl;	
		}
		else if (opt == "e" || opt == "E" || opt == "exit" || opt == "Exit"){
			exit = 0;
		}
		else{
			std::cout << "\nError: Phone book no option finded\n" << std::endl;
		}
	}	
	return 0;
}

