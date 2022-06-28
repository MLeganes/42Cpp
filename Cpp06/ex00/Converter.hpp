/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:19:41 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 12:19:43 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

# include <iomanip>	//std::fixed and precission

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

enum Type {CHAR, INT, FLOAT, DOUBLE, NOTYPE, TYPE_NAN, TYPE_PINF, TYPE_NINF} ;

class Converter
{
private:
	const std::string	_input;
	bool				_errChar;
	bool				_errInt;
	bool				_errFloat;
	bool				_errDoube;

public:
	Converter();
	Converter(const Converter &);
	Converter(std::string input);
	~Converter();

	Converter &operator=(const Converter &);
	std::string getInput() const;

	void	searchType();

	bool	checkNanInf();
	bool	checkChar();
	bool	checkInt();
	bool	checkFloat();
	bool	checkDouble();

	void	printNanInf();
	void	convertToChar();
	void	convertToInt();
	void	convertToFloat();
	void	convertToDouble();

	void	printImpossible();
};

#endif
