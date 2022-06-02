# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.cpp                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:49:33 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:49:38 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}