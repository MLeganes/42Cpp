/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:45:09 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:12 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB
{
private:
	Weapon *weapon;
	const std::string name;

public:
	HumanB(const std::string name);
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
