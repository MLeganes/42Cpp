# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Point.hpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 14:50:31 by amorcill          #+#    #+#              #
#    Updated: 2022/06/02 14:50:33 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
