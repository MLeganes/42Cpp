#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	// Constructors and Destructor.
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);
	~Point();

	// Member functions
	Point &operator=(const Point &copy);
	const Fixed &getX() const;
	const Fixed &getY() const;
};

#endif
