/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:43:29 by amorcill          #+#    #+#             */
/*   Updated: 2022/05/31 15:43:32 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ) {
	
	// 1. Memory reservation
	// Zombie *zmb;
	// zmb = new Zombie(name);
	// zmb->announce();
	//delete zmb;

	// 2. NO-Memory reservation
	Zombie zmb(name);
	zmb.announce();
}
