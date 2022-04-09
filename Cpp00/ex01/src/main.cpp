/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:40:46 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 16:47:58 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// https://en.cppreference.com/w/cpp/symbol_index

int main() {
  PhoneBook agenda;
  std::string opt;
  int exit;

  exit = 1;
  while (exit) {
    std::cout << "\n### Phone Book ###" << std::endl;
    std::cout << " (ADD) Add new contact" << std::endl;
    std::cout << " (SEARCH) Search contact" << std::endl;
    std::cout << " (EXIT) Exit phonebook\n" << std::endl;
    std::cout << "Select one option: ";
    std::getline(std::cin, opt);
    // To capture ^D signal.
    if (std::cin.eof() == true) {
      std::cout << "\nExiting ..." << std::endl;
      std::exit(0);
    }
    if (opt == "ADD")
      agenda.add();
    else if (opt == "SEARCH")
      agenda.search();
    else if (opt == "EXIT")
      exit = 0;
    else
      std::cout << "\nError: Phone book no option finded\n" << std::endl;
  }
  std::exit(EXIT_SUCCESS);
}
