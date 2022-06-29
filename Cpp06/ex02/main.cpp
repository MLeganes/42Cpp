/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:20:38 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 18:59:58 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *base;
	size_t count = 10;

	for (size_t i = 0;themes i < count; i++)
	{
		std::cout << std::endl
				  << "Example casting " << i << std::endl;
		base = generate();
		std::cout << "Identify Class with pointer: " << std::endl;
		identify(*base);
		std::cout << "Identify Class with reference: " << std::endl;
		identify(base);
	}

	return 0;
}

Base *generate(void)
{
	int random = -1;
	Base *ret;

	random = arc4random() % 3;

	switch (random)
	{
	case 0:
		ret = new A();
		break;
	case 1:
		ret = new B();
		break;
	case 2:
		ret = new C();
		break;
	default:
		ret = NULL;
		break;
	}
	return ret;
}

void identify(Base *p)
{
	// https://cplusplus.com/doc/tutorial/typecasting/
	// Dynamic_cast can only be used with pointers and references to classes.
	// When dynamic_cast cannot cast a pointer. It returns a null pointer to indicate the failure.
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Base class A identified" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Base class B identified" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Base class C identified" << std::endl;
}

void identify(Base &p)
{
	// Dynamic_cast is used to convert to a reference type and the conversion is not possible,
	// an exception of type bad_cast is thrown instead.
	try
	{
		// Add static_cast(void) to silent the error: expression result unused.
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "Base class A identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		// Add static_cast(void) to silent the error: expression result unused.
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "Base class B identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		// Add static_cast(void) to silent the error: expression result unused.
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "Base class C identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
