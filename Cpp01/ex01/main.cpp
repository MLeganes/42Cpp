/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:16 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 17:07:31 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>


int main(void){

	std::cout << "\n1. Example: creating..." << std::endl;

	Zombie *zmbs;
	zmbs = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
	{
		zmbs[i].announce();
	}
	std::cout << "\n2. Example: deleting..." << std::endl;
	delete[] zmbs;
	return (0);
}
