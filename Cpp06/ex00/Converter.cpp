/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:19:19 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 12:25:37 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <stdlib.h>

Converter::Converter() : _input("null"){}
Converter::Converter(const Converter &) : _input("null"){}
Converter::Converter(const std::string input) : _input(input)
{
	this->searchType();
}
Converter::~Converter(){}

Converter &Converter::operator=(const Converter &copy) 
{
	if (this == &copy)
		return (*this);

	return (*this);
}

std::string Converter::getInput()const 
{
	return (this->_input);
}

void	Converter::searchType()
{
	if (this->checkNanInf())
		printNanInf();
	else if (checkChar())
		convertToChar();
	else if (checkInt())
		convertToInt();
	else if (this->checkFloat())
		convertToFloat();
	else if (this->checkDouble())
		this->convertToDouble();
	else
		printImpossible();
}

bool	Converter::checkNanInf()
{
	if ((this->_input == "+inff") || (this->_input == "-inff") || (this->_input == "nanf")  ||
		(this->_input == "+inf")  || (this->_input == "-inf")  || (this->_input == "nan"))
		return true;
	return false;
}
bool	Converter::checkChar()
{
	if ( this->_input.length() == 1 && !isdigit(this->_input[0]) && isprint(this->_input[0]))
		return true;
	return false;
}
bool	Converter::checkInt()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int> (this->_input.length());

	if (_input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for(; i < len; i++)
	{
		if (!isdigit(this->_input[i]))
			return false;
	}

	unsigned int i_dec;
	if (sign == -1)
	{
		const char *i_ptr = &this->_input[1];
		i_dec = atoi(i_ptr);
	}
	else
	{
		const char *i_ptr = &this->_input[0];
		i_dec = atoi(i_ptr);
	}
	// 2147483647,	-2147483648
	if ((sign == -1 && i_dec > 2147483648) || (sign == 1 && i_dec > 2147483647))
	{
		return false;
	}
	return true;
}

bool	Converter::checkFloat()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int> (this->_input.length());

	if (_input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for(; i < len; i++)
	{
		if (!(isdigit(this->_input[i]) || this->_input[i] == '.' || this->_input[i] == 'f'))
		{
			return false;
		}
	}

	if (this->_input.find_first_of("f") != this->_input.find_last_of("f") ||		// catches `0.0ff`
		this->_input.find_first_of(".") != this->_input.find_last_of(".") ||		// catches `0..0f`
		this->_input.find_first_of("f") - this->_input.find_first_of(".") == 1 ||	//catches `0.f`
		this->_input.find_first_of(".") == 0 ||										// catches `.0f`
		this->_input[this->_input.find_first_of("f") + 1] != '\0')					// catches `0.0f0`
		return false;
	return true;
}

bool Converter::checkDouble()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int> (this->_input.length());

	if (_input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for(; i < len; i++)
	{
		if (!(isdigit(this->_input[i]) || this->_input[i] == '.'))
		{
			return false;
		}
	}

	if (this->_input.find_first_of(".") != this->_input.find_last_of(".") ||		// catches `0..0`
		(this->_input.find_last_of(".") - (std::strlen(this->_input.c_str()) - 1)  == 0 ) )	//catches `0.`
		return false;

	char *end;
	std::strtod(this->_input.c_str(), &end);
	if (errno == ERANGE)
	{
		return false;
	}
	return true;
}

void	Converter::printNanInf()
{
	if (this->_input == "-inf" || this->_input == "-inff")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: -inff " << std::endl;
		std::cout << "double: -inf " << std::endl;
	}
	if (this->_input == "+inf" || this->_input == "+inff")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: +inff " << std::endl;
		std::cout << "double: +inf " << std::endl;
	}
	if (this->_input == "nan")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: nanf " << std::endl;
		std::cout << "double: nan " << std::endl;
	}
	if (this->_input == "nanf")
	{
		std::cout << "error: impossible convertion" << std::endl;
	}
}
void	Converter::convertToChar()
{
	char c = this->_input[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void	Converter::convertToInt()
{
	const char *i_ptr = &this->_input[0];
	int i_dec = atoi(i_ptr);

	// PRINTING PART
	std::cout << std::fixed << std::setprecision(1);
	char c = static_cast<char>(i_dec);
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i_dec << std::endl;
	std::cout << "float: " << static_cast<float>(i_dec) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i_dec) << std::endl;
}
void	Converter::convertToFloat()
{
	_errChar = false;
	_errInt = false;
	_errFloat = false;
	_errDoube = false;
	char c;
	int i;

	// CHECKING PART
	char *end;
	float f =  static_cast<float>(std::strtod(this->_input.c_str(), &end));
	if (errno == ERANGE)
	{
		_errInt = true;
		_errFloat = true;
		_errChar = true;
	}

	// CHAR 
	long intCheckL = static_cast<long>(f);
	if (intCheckL > std::numeric_limits<char>::max() || intCheckL < std::numeric_limits<char>::min())
	{	
		_errChar = true;
	}
	else
		c = static_cast<char>(f);

	// INT
	if (intCheckL > std::numeric_limits<int>::max() || intCheckL < std::numeric_limits<int>::min())
	{	
		_errInt = true;
	}
	else
		i = static_cast<int>(f);

	// PRINTING PART
	std::cout << std::fixed << std::setprecision(1);
	// CHAR
	if ( _errChar == true)
		std::cout << "char: impossible" << std::endl;
	else if ( isprint(c) == false || isnumber(c) == true)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	// INT
	if (_errInt == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	// FLOAT
	if (_errFloat == true)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << this->_input << std::endl;
	// DOUBLE
	if (_errFloat)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}
void	Converter::convertToDouble()
{
	_errChar = false;
	_errInt = false;
	_errFloat = false;
	_errDoube = false;
	char c;
	int i;

	// CHECKING PART
	char *end;
	double d =  std::strtod(this->_input.c_str(), &end);
	if (errno == ERANGE)
	{
		_errChar = true;
		_errInt = true;
		_errFloat = true;
		_errDoube = true;
	}

	// CHAR 
	long intCheckL = static_cast<long>(d);
	if (intCheckL > std::numeric_limits<char>::max() || intCheckL < std::numeric_limits<char>::min())
		_errChar = true;
	else
		c = static_cast<char>(d);

	// INT
	if (intCheckL > std::numeric_limits<int>::max() || intCheckL < std::numeric_limits<int>::min())
		_errInt = true;
	else
		i = static_cast<int>(d);

	// PRINTING PART
	std::cout << std::fixed << std::setprecision(1);
	// CHAR
	if ( _errChar == true)
		std::cout << "char: impossible" << std::endl;
	else if ( isprint(c) == false || isnumber(c) == true)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	// INT
	if (_errInt == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	// FLOAT
	if (_errFloat == true)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	// DOUBLE
	if (_errFloat)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << this->_input << std::endl;
}


void Converter::printImpossible()
{
	std::cout << "char: invalid type" << std::endl;
	std::cout << "int: invalid type " << std::endl;
	std::cout << "float: invalid type " << std::endl;
	std::cout << "double: invalid type " << std::endl;
}
