/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/25 21:51:49 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
  std::string name;

public:
  				Zombie(std::string name);
  				~Zombie();
  void			announce();
  void			setName(std::string name);
  std::string	getName(void);
};

Zombie* zombieHorde( int N, std::string name);

#endif