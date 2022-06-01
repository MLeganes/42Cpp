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
