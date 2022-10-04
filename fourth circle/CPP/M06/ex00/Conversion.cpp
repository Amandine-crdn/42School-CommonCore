#include "Conversion.hpp"

Conversion::Conversion(char const *s){
	if (Conversion::isDouble(s) == true);
	else if (Conversion::isFloat(s) == true) ;
	else if (Conversion::isInt(s) == true);
	else if (Conversion::isChar(s) == true);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}	
}

Conversion::Conversion(Conversion const &cpy){
	*this = cpy;
}

Conversion	&Conversion::operator=(Conversion const &op) {
	if (this != &op)
		*this = op;
	return (*this);
}

bool Conversion::isFloat(char const *s){
	char *endptr = NULL;
	float f = strtof(s, &endptr);
	if (*endptr != 'f' || *(endptr + 1) != 0);
	else
	{
		if (f > 127 || f < 0)
			std::cout << "char: impossible" << std::endl;
		else if ((f >= 0 && f < 32) || f == 127)
			std::cout << "char: non displayable" << std::endl;
		else if (std::isnan(f))
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

		if (static_cast<int>(f) < INT_MIN || static_cast<int>(f) > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else if (std::isnan(f))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " <<  static_cast<double>(f) << std::endl;
		return (true);
	}
	return (false);
}

bool Conversion::isDouble(char const *s){
	char *endptr = NULL;
	double d = strtod(s, &endptr);
	if (*endptr);
	else
	{
		if (d > 127 || d < 0)
			std::cout << "char: impossible" << std::endl;
		else if ((d >= 0 && d < 32) || d == 127)
			std::cout << "char: non displayable" << std::endl;
		else if (std::isnan(d))
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		
		if (d < INT_MIN || d > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else if (std::isnan(d))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return (true);
	}
	return (false);
}

bool Conversion::isInt(char const *s){
	char *endptr = NULL;
	long i = strtol(s, &endptr, 10);
	if (*endptr);
	else if (i < INT_MIN || i > INT_MAX);
	else
	{
		if (i > 127 || i < 0)
			std::cout << "char: impossible" << std::endl;
		else if ((i >= 0 && i < 32) || i == 127)
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(i) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << i << std::endl;
		return (true);
	}
	return (false);
}

bool Conversion::isChar(char const *s){
	if (s && s[1]);
	else
	{
		std::cout << "char: '" << s[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(s[0]) << std::endl;
		return (true);
	}
	return (false);
}