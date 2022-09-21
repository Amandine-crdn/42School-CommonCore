#include "Fixed.hpp"

int main( void )
{
   /* Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    *//////
    Fixed e(13); //Fixed::Fixed(int const n_const)
    e.toInt();//int Fixed::toInt( void ) const
    Fixed f(13.5f); //Fixed::Fixed(float const float_const)
    f.toFloat(); //float Fixed::toFloat( void ) const
    return 0;
}