/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/25 16:58:33 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
  std::string _name;

public:
  Zombie(std::string name);
  ~Zombie();
  void announce();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif