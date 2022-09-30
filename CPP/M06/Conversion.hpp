#ifndef CONVERSION_HPP
#   define CONVERSION_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <climits>
# include <iomanip> // checker les necessaires
#include <cfloat>


class Conversion
{
	public:
        Conversion() {};
		Conversion(char const *s);
		Conversion(Conversion const &cpy); // operateur pas tous ecrit
		Conversion &operator=(Conversion const &op);
		~Conversion() {};

		bool isChar(char const *s);
		void resultChar();
		bool isInt(char const *s);
		bool isDouble(char const *s);
		bool isFloat(char const *s);
};	


#endif