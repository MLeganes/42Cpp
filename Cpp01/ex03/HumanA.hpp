/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:44:53 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA
{
private:
	Weapon &weapon;
	const std::string name;

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
