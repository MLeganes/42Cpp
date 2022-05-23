/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:21 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/20 16:49:54 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma 
#include <iostream>
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#endif

class Zombie {
private:
  /* data */
  std::string _name;

public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
};
