/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:19:47 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 12:31:26 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>

#include "Converter.hpp"

#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"

int main(int argc, char *argv[])
{

	if ((argc != 2) || (argc == 2 && argv[1] && strlen(argv[1]) == 0))
	{
		std::cout << "error: 1 argument input needed for conversion, char, int, float or double. Example: ./converter 42" << std::endl;
		return 1;
	}

	try
	{
		// std::cout << "input parameter: " << argv[1] << std::endl;
		Converter cvt(argv[1]);
		/* code */
	}
	catch (const std::exception &e)
	{
		std::cout << RED;
		std::cerr << e.what() << '\n';
		std::cout << WHITE;
	}
	return 0;
}
