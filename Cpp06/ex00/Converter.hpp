#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <stdlib.h>

enum Type {CHAR, INT, FLOAT, DOUBLE, NOTYPE, TYPE_NAN, TYPE_PINF, TYPE_NINF} ;

class Converter
{
private:
	std::string			_input;
	char				*_arg;
	Type				_type;
	char				_char;
	int					_int;
	float				_float;
	double				_double;

public:
	Converter();
	Converter(const Converter &);
	Converter(std::string &);
	Converter(char *arg);
	~Converter();

	Converter &operator=(const Converter &);

	Type	getType() const;
	char 	getChar() const;
	int 	getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	void	searchType();

	bool	checkNanInf();
	bool	checkChar();
	bool	checkInt();
	bool	checkFloat();

	void	printNanInf();
	void	convertToChar();
	void	convertToInt();
	void	convertToFloat();
	void	convertToDouble();

};

#endif
