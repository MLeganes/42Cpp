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
	if (this->_input.length() == 0)
	{
		std::cout << " This is NO-TYPE" << std::endl;
		this->_type = NOTYPE;
	}

	if ((this->_input.compare("-inff") == 0) || (this->_input.compare("-inf") == 0))
	{
		this->_type = TYPE_NINF;
		// std::cout << std::endl << " Type:  " << this->_type << std::endl;
		this->printNanInf();
		return ;
	}
	if ((this->_input.compare("+inff") == 0) || (this->_input.compare("+inf") == 0))
	{
		this->_type = TYPE_PINF;
		// std::cout << std::endl << " Type:  " << this->_type << std::endl;
		this->printNanInf();
		return ;
	}
	if ((this->_input.compare("nanf") == 0) || (this->_input.compare("nan") == 0))
	{
		this->_type = TYPE_NAN;
		// std::cout << std::endl << " Type:  " << this->_type << std::endl;
		this->printNanInf();
		return ;
	}
	

	/*
	 * Integer
	 */
	char *end;
	long res = strtol(this->_input.c_str(), &end, 10);
	//std::cout << " This is res: " <<  res << std::endl;
	if (errno == ERANGE)
	{
		std::cout << " Error: erange " << res << std::endl;
		//return NOTYPE;
	}

	if (res > INT_MAX || res < INT_MIN)
	{
		std::cout << " This is NOT an INT " << res << std::endl;
	}
	else
	{
		std::cout << " This is INT " << res << std::endl;
		_int = res;
	}

	/*
	 * Float
	 */
	end = nullptr;
	float resFloat = strtof(this->_input.c_str(), &end);
	if (errno == ERANGE)
		std::cout << " Error: erange in float" << resFloat << std::endl;
	else
		std::cout << " This is float " << res << std::endl;

	/*
	 * Double
	 */
	double resDouble;
	try
	{
		resDouble = strtod(this->_input.c_str(), &end);
	}
	catch(const std::exception& e)
	{
		std::cerr << " Error: erange in double " << resDouble << e.what() << '\n';
	}
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

void Converter::printNanInf()
{

// 	 amorcill@1-B-4 ex00 % ./convert nanf 
//	 error: not convertable

	if (this->_type == TYPE_NINF)
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: -inff " << std::endl;
		std::cout << "double: -inf " << std::endl;
	}
	if (this->_type == TYPE_PINF)
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: +inff " << std::endl;
		std::cout << "double: +inf " << std::endl;
	}
	if (this->_type == TYPE_NAN)
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: nanf " << std::endl;
		std::cout << "double: nan " << std::endl;
	}
}

