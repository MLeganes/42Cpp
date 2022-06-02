# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.cpp                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:48:25 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:48:28 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}
