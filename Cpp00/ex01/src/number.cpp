#include "../inc/number.hpp"

bool isnumber(std::string number){
	int i = 0;
	while ( i < (int)number.length()){
		if (isdigit(number[i]) == false)
			return false;
		i++;
	}
	return true;
}