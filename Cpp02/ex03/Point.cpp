#include "Point.hpp"

// Constructors and Destructor.
Point::Point() : _x(), _y() {}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point() {}

// Member functions
Point &Point::operator=(const Point &copy)
{
	(void)copy;
	return (*this);
}
const Fixed &Point::getX() const
{
	return (this->_x);
}
const Fixed &Point::getY() const
{
	return (this->_y);
}
