# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Fixed.hpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:48:12 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:48:14 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int _value;						// to store the fixed-point number value.
	static const int _bits = 8;		// to store the number of fractional bits, always 8.

public:
	// Constructors and Destructor.
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();

	// Member functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(const Fixed &copy);
};

#endif
