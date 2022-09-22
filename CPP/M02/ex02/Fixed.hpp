#ifndef FIXED_HPP
# define FIXED_HPP

    #include <iostream>
    #include <cmath>

    class Fixed
    {
        public:
            Fixed( void );
            ~Fixed( void );
            Fixed(Fixed const &copy);
            Fixed & operator=(Fixed const &op);

            int getRawBits( void ) const;
            void setRawBits( int const raw );

            //ex01
            Fixed(int const n_const);
            Fixed(float const float_const);
            int toInt( void ) const;
            float toFloat( void ) const;

            //ex02
            //comparaison
            bool operator>(Fixed const &op);
            bool operator<(Fixed const &op);
            bool operator<=(Fixed const &op);
            bool operator>=(Fixed const &op);
            bool operator==(Fixed const &op);
            bool operator!=(Fixed const &op);
            //arithmetie
            Fixed operator+(Fixed const &op);
            Fixed operator-(Fixed const &op);
            Fixed operator*(Fixed const &op);
            Fixed operator/(Fixed const &op);
            //incrementation
            Fixed& operator ++ ( void ); 
            Fixed& operator -- ( void );
            Fixed operator++( int );
            Fixed operator -- ( int );
            //static
            static Fixed& min(Fixed &op1, Fixed &op2);
            static const Fixed&  min(Fixed const &op1, Fixed const &op2); // statique prk enonce ? utilite ?
            static Fixed& max(Fixed &op1, Fixed &op2);
            static const Fixed& max(Fixed const &op1, Fixed const &op2);

        private:
            int _n;
            const static int _bits = 8;
    }; 

std::ostream &operator<<(std::ostream &op, const Fixed &a);

#endif