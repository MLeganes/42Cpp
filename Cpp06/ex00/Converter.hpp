#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <stdlib.h>

enum Type {CHAR, INT, FLOAT, DOUBLE, NOTYPE, TYPE_NAN, TYPE_PINF, TYPE_NINF} ;

class Converter
{
private:
	const std::string	_input;
	Type				_type;
	char				_char;
	int					_int;
	float				_float;
	double				_double;

public:
	Converter();
	Converter(const Converter &);
	Converter(const std::string &);
	~Converter();

	Converter &operator=(const Converter &);

	Type	getType() const;
	char 	getChar() const;
	int 	getInt() const;
	float	getFloat() const;
	double	getDouble() const;



	char	convertToChar();
	void	convertToInt();
	float	convertToFloat();
	double	convertToDouble();

	void	printConvertion();

	void	searchType();

	bool	checkNanInf();
	void	printNanInf();

	bool	checkInt();
	void	printInt();
	//bool	checkMinus();
};

#endif
