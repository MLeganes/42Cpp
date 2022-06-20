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
		throw invalid_argument("No argumen valid");
}

char	Converter::convertToChar(const std::string &)
{
return '\0';
}
int		Converter::convertToInt(const std::string &)
{
	return 0;
}
float	Converter::convertToFloat(const std::string &)
{
	return 0.0;
}
double	Converter::convertToDouble(const std::string &)
{
	return 0.0;
}


