/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/27 16:15:16 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
  std::string name;

public:
  //member function is a function that is defined as part of a class.
  //Member functions are sometimes referred to as methods
  				Zombie();
  				Zombie(std::string name);
  				~Zombie();
  void			announce();
  void			setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);

#endif