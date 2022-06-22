#include "Converter.hpp"

Converter::Converter() : _input("null")
{
}
Converter::Converter(const Converter &) : _input("null")
{
	
}
Converter::Converter(const std::string &str) : _input(str)
{
	this->searchType();
}
Converter::~Converter()
{
}

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
	std::cout << "Converter-searchType member function called " << std::endl;

	if (this->checkNanInf())
		this->printNanInf();
	else if (checkInt())
		convertToInt();
	// else if (this->checkFloat())
	// 	this->printFloat();
	// else if (this->checkDouble())
	// 	this->printDouble();

	/*
	 * Float
	 */
	// end = nullptr;
	// float resFloat = strtof(this->_input.c_str(), &end);
	// if (errno == ERANGE)
	// 	std::cout << " Error: erange in float" << resFloat << std::endl;
	// else
	// 	std::cout << " This is float " << res << std::endl;

	// /*
	//  * Double
	//  */
	// double resDouble;
	// try
	// {
	// 	resDouble = strtod(this->_input.c_str(), &end);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << " Error: erange in double " << resDouble << e.what() << '\n';
	// }
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


char	Converter::convertToChar()
{
	return (this->_input[0]);
}
void	Converter::convertToInt()
{
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
float	Converter::convertToFloat()
{
	return strtof((this->_input).c_str(), 0L);
}
double	Converter::convertToDouble()
{
	return strtod((this->_input).c_str(), 0L);
}
void	Converter::printConvertion()
{
	//get type

	//switch and print every case


}
bool	Converter::checkNanInf()
{
	if ((this->_input == "+inff") || (this->_input == "-inff") || (this->_input == "nanf")  ||
		(this->_input == "+inf")  || (this->_input == "-inf")  || (this->_input == "nan"))
		return true;
	return false;
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


