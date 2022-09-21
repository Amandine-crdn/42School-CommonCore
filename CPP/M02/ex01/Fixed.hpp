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
            float toFloat( void ) const;
            int toInt( void ) const;
        
        private:
            int _n;
            const static int _bits = 8;
    }; 

std::ostream &operator<<(std::ostream &op, const Fixed &a);

#endif