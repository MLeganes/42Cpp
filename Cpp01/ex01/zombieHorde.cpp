/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:44:15 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:44:18 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	// This is the way to allowate the N zombies.
	Zombie *zmbs = new Zombie[N]();

	for (int i = 0; i < N; i++)
		zmbs[i].setName(name);
	return (zmbs);
}
