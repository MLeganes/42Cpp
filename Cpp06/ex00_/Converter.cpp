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
	this->_type = copy.getType();
	this->_char = copy.getChar();
	this->_int = copy.getInt();
	this->_float = copy.getFloat();
	this->_double = copy.getDouble();
	return (*this);
}

Type	Converter::getType() const{return this->_type;}
char 	Converter::getChar() const{return this->_char;}
int 	Converter::getInt() const{return this->_int;}
float	Converter::getFloat() const{return this->_float;}
double	Converter::getDouble() const{return this->_double;}


void	Converter::searchType()
{
	// std::cout << "Converter-searchType member function called " << std::endl;

	if (this->checkNanInf())
		printNanInf();
	else if (checkChar())
		convertToChar();
	else if (checkInt())
		convertToInt();
	else if (this->checkFloat())
		convertToFloat();
	// else if (this->checkDouble())
	// 	this->printDouble();
	else
		printImpossible();
	//throw std::overflow_error("error: the type conversion is impossible.");

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
		// std::cout << "atoi result: " <<  i_dec << "INT OUT OF RANGE " << std::endl;
		return false;
	}
	// std::cout << "atoi result: " <<  i_dec << std::endl;
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
		//if (!isdigit(this->_input[i]) && this->_input[i] == '.' && this->_input[i] == 'f')
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
	std::cout << " convert To CHAR " << std::endl;
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void	Converter::convertToInt()
{
	std::cout << " convert To Int " << std::endl;
	const char *i_ptr = &this->_input[0];
	int i_dec = atoi(i_ptr);

	char c = static_cast<char>(i_dec);
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i_dec << std::endl;
	std::cout << "float: " << static_cast<float>(i_dec) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i_dec) << ".0" << std::endl;
}
void	Converter::convertToFloat()
{
	_errInt = false;
	_errFloat = false;
	_errDoube = false;
	// https://en.cppreference.com/w/cpp/string/byte/strtol
	// Defined in header <cstdlib>
	// long      strtol( const char *str, char **str_end, int base );
	char *end;
	// std::cout << " **** FLOAT MAX: " << std::numeric_limits<float>::max() <<std::endl;
	// std::cout << " **** FLOAT MIN: " << std::numeric_limits<float>::min() <<std::endl;

	double d = std::strtod(this->_input.c_str(), &end);
	if (errno == ERANGE)
	{
		//throw std::overflow_error("overflow error in parser to double");
		_errDoube = true;
	}
	
	// std::cout << " **** double: " << d <<std::endl;
	float f = static_cast<float>(d);
	// std::cout << " **** float: " << d <<std::endl;
	if (errno == ERANGE)
	{
		//throw std::overflow_error("overflow error in parser to double");
		_errFloat = true;
	}

	// if (static_cast<float>(d) > std::numeric_limits<float>::max() || static_cast<float>(d) < std::numeric_limits<float>::min())
	// {
	// 	std::cout << RED << " **** convert To FLOAT " << WHITE <<std::endl;
	// 	throw std::overflow_error("error: the type conversion is impossible. Overflow error in parser to float");
	// }


	char c = static_cast<char>(f);
	if (isprint(c) && !isdigit(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	int i = static_cast<int>(f);
	if (i >= -2147483648 || i <= 2147483647)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: Non displayable" << std::endl;
	if (_errFloat)
		std::cout << "float: Non displayable" << std::endl;
	else
		std::cout << "float: " << this->_input << std::endl;
	if (_errDoube)
		std::cout << "double: Non displayable" << std::endl;
	else
		std::cout << "double: " << d << std::endl;

}
void	Converter::convertToDouble()
{
	// https://en.cppreference.com/w/cpp/string/byte/strtof
	// double      strtod( const char* str, char** str_end );
	 strtod((this->_input).c_str(), 0L);
}


void Converter::printImpossible()
{
	std::cout << "char: impossible, invalid type" << std::endl;
	std::cout << "int: impossible, invalid type " << std::endl;
	std::cout << "float: impossible, invalid type " << std::endl;
	std::cout << "double: impossible, invalid type " << std::endl;
}
