/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:53:48 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/27 16:15:09 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string name) {

	// 1. one way to asignate the value.
	this->name = name;

	// 2. another way to asignate the value.
	// Zombie::name = name

	// 3. another way to asignate the value. Only working for const.
	// Zombie::Zombie(std::string n): name(n)

	std::cout << this->name << ": constructor" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << ": deconstructor" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	// 1. one way
	this->name = name;

	// 2. another way
	// Zombie::name = name

}
