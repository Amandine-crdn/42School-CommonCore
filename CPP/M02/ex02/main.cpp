#include "Fixed.hpp"

int main( void )
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout <<"ici " << b << std::endl;
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    Fixed a(5);
    //std::cout << a << std::endl;
   // Fixed d;
    //test comparaison
    // std::cout << d.getRawBits() << std::endl;
    // std::cout << (d > a) <<  std::endl;
    //test arithmetie
    Fixed e(10);
    
    std::cout << a + e << std::endl;
   
    return 0;
}