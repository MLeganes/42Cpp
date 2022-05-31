/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:45:25 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:27 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){}
Weapon::~Weapon(void){}
Weapon::Weapon(const std::string &type) : type(type){}

const std::string &Weapon::getType() const{
	return (this->type);
}

void Weapon::setType(const std::string &type){
	Weapon::type = type;
}
