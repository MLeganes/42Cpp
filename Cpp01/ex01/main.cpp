/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:16 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/27 15:31:15 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>


int main(void){

	// 1. Example: create an array of Zombies
	std::cout << "\n1. Example: creating..." << std::endl;

	Zombie *zmbs;
	zmbs = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
	{
		zmbs->announce();
	}
	std::cout << "\n1. Example: deleting..." << std::endl;
	// Delete the array of zombies.
	delete[] zmbs;
	return (0);
}
