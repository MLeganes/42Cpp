/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:50:14 by amorcill          #+#    #+#             */
/*   Updated: 2022/07/07 14:26:23 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point  a, Point b, Point c, Point point);

int main() {
	const Point a(0, 0);
	const Point b(10, 0);
	const Point c(0, 10);
	const Point p(6, 6);
	std::cout << "Point x=" << p.getX() << " y=" << p.getY() << " is " << (bsp(a, b, c, p) ? "inside" : "outside") << std::endl;
	
	const Point a1(0, 0);
	const Point b1(10, 0);
	const Point c1(0, 10);
	const Point p1(5, 0);
	std::cout << "Point x=" << p1.getX() << " y=" << p1.getY() << " is " << (bsp(a1, b1, c1, p1) ? "inside" : "outside") << std::endl;

	return (0);
}