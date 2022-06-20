#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <stdexcept>

enum Type {CHAR, INT, FLOAT, DOUBLE} ;

class Converter
{
private:
	const std::string _input;
	
public:
	Converter();
	Converter(const Converter &);
	Converter(const std::string &);
	~Converter();

	Converter &operator=(const Converter &);

	Type	getType();
	char	convertToChar(const std::string &);
	int		convertToInt(const std::string &);
	float	convertToFloat(const std::string &);
	double	convertToDouble(const std::string &);

	class ConverterTypeException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class ConverterCharException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class ConverterIntException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class ConverterFloatxception : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class ConverterDoubleException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
};

#endif
