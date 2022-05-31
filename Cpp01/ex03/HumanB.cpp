/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:45:01 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:03 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : weapon(NULL), name(name) {}

void HumanB::attack()
{
	std::cout << this->name << " atacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon; // Weapon past as Reference, save the address of the weapon in a pointer.
}
