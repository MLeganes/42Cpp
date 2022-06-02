# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Fixed.cpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:49:56 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:49:58 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "Fixed.hpp"

// Constructors and Destructor.
Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f)
{
	this->_value = (int)roundf(f * (1 << this->_bits));
}

Fixed::~Fixed()
{
}

// Member functions
int Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	this->_value = copy.getRawBits();
	return (*this);
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}
float Fixed::toFloat(void) const
{
	return ((float)this->_value) / (1 << this->_bits);
}

// Overload Member functions: comparison operators: >, <, >=, <=, == and !=
bool Fixed::operator>(const Fixed &compar) const
{
	return this->toFloat() > compar.toFloat();
}
bool Fixed::operator<(const Fixed &compar) const
{
	return this->toFloat() < compar.toFloat();
}
bool Fixed::operator>=(const Fixed &compar) const
{
	return this->toFloat() >= compar.toFloat();
}
bool Fixed::operator<=(const Fixed &compar) const
{
	return this->toFloat() <= compar.toFloat();
}
bool Fixed::operator==(const Fixed &compar) const
{
	return this->toFloat() == compar.toFloat();
}
bool Fixed::operator!=(const Fixed &compar) const
{
	return this->toFloat() != compar.toFloat();
}

// Overload Member functions: arithmetic operators: +, -, *, and /
Fixed Fixed::operator+(const Fixed &compar) const
{
	return (Fixed)(this->toFloat() + compar.toFloat());
}
Fixed Fixed::operator-(const Fixed &compar) const
{
	return (Fixed)(this->toFloat() - compar.toFloat());
}
Fixed Fixed::operator*(const Fixed &compar) const
{
	return (Fixed)(this->toFloat() * compar.toFloat());
}
Fixed Fixed::operator/(const Fixed &compar) const
{
	return (Fixed)(this->toFloat() / compar.toFloat());
}

// Overload Member functions: increment/decrement.
Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}
Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

// Overload Member functions: min/max.
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a <= b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
}

// Function to the Fixed class.
std::ostream &operator<<(std::ostream &ost, const Fixed &fixed)
{
	ost << fixed.toFloat();
	return (ost);
}
