/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:16 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/27 13:17:43 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>


int main(void){
	
	// 1. Example: create a Zombie with the class
	std::cout << "\n1. Example" << std::endl;
	Zombie *zmb1;
	zmb1 = newZombie("Zombie1");
	zmb1->announce();
	delete zmb1;

	// 2. Example 
	std::cout << "\n2. Example" << std::endl;
	randomChump("Zombie2");
	
	return (0);
}
