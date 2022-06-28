/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:20:04 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 12:27:12 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>

#include <stdint.h>

#define GREEN "\033[1;32m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"

typedef struct s_Data
{
	std::string str;
	char c;
	int i;
	float f;
	double d;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

int main()
{
	Data *data = new Data();
	uintptr_t rawData;

	data->str = "hello 42 heilbronn";
	data->c = 'H';
	data->i = 42;
	data->f = 42.42f;
	data->d = 42.42;

	std::cout << "Data before serialization " << std::endl;
	std::cout << "Data string: " << data->str << std::endl;
	std::cout << "Data char  : " << data->c << std::endl;
	std::cout << "Data int   : " << data->i << std::endl;
	std::cout << "Data float : " << data->f << std::endl;
	std::cout << "Data double: " << data->d << std::endl;

	rawData = serialize(data);

	std::cout << std::endl
			  << "Pointer to rawData " << &rawData << std::endl;

	data = deserialize(rawData);

	std::cout << std::endl
			  << "Data after deserialization " << std::endl;
	std::cout << "Data string: " << data->str << std::endl;
	std::cout << "Data char  : " << data->c << std::endl;
	std::cout << "Data int   : " << data->i << std::endl;
	std::cout << "Data float : " << data->f << std::endl;
	std::cout << "Data double: " << data->d << std::endl;

	delete data;

	return 0;
}

uintptr_t serialize(Data *ptr)
{
	//https://cplusplus.com/doc/tutorial/typecasting/
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
