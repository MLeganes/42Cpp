/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:16 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/27 17:13:33 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>


int main(void){

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;	// A pointer to the string
	std::string &stringREF = str;	// A reference to the string.

	std::cout << "The memory address of the string variable "	<< &str << std::endl;
	std::cout << "The memory address held by stringPTR "	<< stringPTR << std::endl;
	std::cout << "The memory address held by stringREF "	<< &stringREF << std::endl;
	
	std::cout << "The value of the string variable " 		<< str << std::endl;
	std::cout << "The value pointed to by stringPTR "		<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF "		<< stringREF << std::endl;

	return (0);
}
