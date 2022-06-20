#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <iostream>

enum class Type {CHAR, INT, FLOAT, DOUBLE };

class Converter
{
private:
	
public:
	Converter();
	Converter(const Converter &);
	~Converter();

	Converter &operator=(const Converter &);

	Type	getType(const std::string &);
	char	convertToChar(const std::string &);
	int		convertToInt(const std::string &);
	float	convertToFloat(const std::string &);
	double	convertToDouble(const std::string &);

	
};

#endif
