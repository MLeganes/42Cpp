#include "Converter.hpp"

Converter::Converter() : _input("null")
{
}

Converter::Converter(const Converter &) : _input("null")
{
	
}

Converter::Converter(const std::string &str) : _input(str)
{
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &)
{
	return (*this);
}

Type	Converter::getType()
{
	if (this->_input.length() == 0)
		return NOTYPE;
	// int
	char *end;
	unsigned int res = strto
	// float
	// double
}	

char	Converter::convertToChar()
{
	return (this->_input[0]);
}
int		Converter::convertToInt()
{
	return static_cast<int>(strtof((this->_input).c_str(), 0L));
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

