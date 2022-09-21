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
    /////////////////
    
    //test constructeur
    Fixed a(5);
    std::cout << a << std::endl;
    std::cout << a.getRawBits() << std::endl;
    //test comparaison
    Fixed d;
    std::cout << d.getRawBits() << std::endl;
    std::cout << (d > a) <<  std::endl;
    // test arithmetie
    Fixed e(10);
    std::cout << a + e << std::endl;
    std::cout << a << std::endl; // valeur non changer
    std::cout << a.getRawBits() << std::endl;
     std::cout << "coucou\n";
    // test incrementation
    a.operator++();
    std::cout << a.getRawBits() << std::endl;
    return 0;
}