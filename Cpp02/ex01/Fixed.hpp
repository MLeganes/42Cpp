# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Fixed.hpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:48:55 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:48:57 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;						// to store the fixed-point number value.
	static const int _bits = 8;		// to store the number of fractional bits, always 8.

public:
	// Constructors and Destructor.
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();

	// Member functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(const Fixed &copy);
	int		toInt(void) const;
	float	toFloat(void) const;
};

// Function to the Fixed class.
// Overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream &ost, const Fixed &fixed);

#endif
