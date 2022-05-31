/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:45:32 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:35 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
private:
	std::string type;

public:
	Weapon(void);
	~Weapon(void);
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &type);
};

#endif
