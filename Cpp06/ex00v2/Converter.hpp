#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

# include <iomanip>	//std::fixed and precission

# define GREEN	"\033[1;32m"
# define WHITE	"\033[0;37m"
# define RED	"\033[31m"

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
	bool				_errChar;
	bool				_errInt;
	bool				_errFloat;
	bool				_errDoube;

public:
	Converter();
	Converter(const Converter &);
	Converter(std::string input);
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
	bool	checkDouble();

	void	printNanInf();
	void	convertToChar();
	void	convertToInt();
	void	convertToFloat();
	void	convertToDouble();

	void	printImpossible();
};

#endif
