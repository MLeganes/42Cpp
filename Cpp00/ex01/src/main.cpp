/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:40:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 16:10:18 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.class.hpp"
#include "../inc/PhoneBook.class.hpp"

//https://en.cppreference.com/w/cpp/symbol_index

int main() {
  PhoneBook agenda;
  std::string opt;
  int exit;

  exit = 1;
  while (exit) {
    std::cout << "\n### Phone Book ###" << std::endl;
    std::cout << " (A) Add new contact" << std::endl;
    std::cout << " (S) Search contact" << std::endl;
    std::cout << " (E) Exit phonebook\n" << std::endl;
    std::cout << "Select one option: ";
	std::getline(std::cin, opt);
	// To capture ^D signal.
	if (std::cin.eof() == true){
		std::cout << "\nExiting ..." << std::endl;
		std::exit(0);
	}
    if (opt == "a" || opt == "A" || opt == "add" || opt == "Add")
      agenda.add();
    else if (opt == "s" || opt == "S" || opt == "search" || opt == "Search")
      agenda.search();
    else if (opt == "e" || opt == "E" || opt == "exit" || opt == "Exit")
      exit = 0;
    else
      std::cout << "\nError: Phone book no option finded\n" << std::endl;
  }
  std::exit(EXIT_SUCCESS);
}
