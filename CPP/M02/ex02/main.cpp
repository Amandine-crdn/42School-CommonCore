#include "Fixed.hpp"

int main( void )
{
    /*Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout <<"ici " << b << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    */
    /////////////////
    
    Fixed a(-8388607);
    Fixed b(10);
    std::cout << "a = " << a << " b = " << b << std::endl;
    
    //test constructeur
    std::cout << "ICCCCI  = " << a << std::endl;
    std::cout << a.getRawBits() << std::endl;
    //test comparaison
    std::cout << "test comparaison\n";
    Fixed d;
    std::cout << d.getRawBits() << std::endl;
    std::cout << (d > a) <<  std::endl; //false ou true
    // test arithmetie
    std::cout << "test arithmetie\n";
    Fixed e(10);
    std::cout << a + e << std::endl;
    std::cout << a.getRawBits() << std::endl;// valeur non changer
    // test incrementation
    std::cout << "test incrementation\n";
    std::cout << "----- 0\n";
    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;  // valeur changee
    std::cout << "----- a++\n";
    a++;
    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
    std::cout << "----- ++a\n";
    ++a;
    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;

    return 0;
  
}