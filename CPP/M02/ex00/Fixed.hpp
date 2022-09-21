#ifndef FIXED_HPP
# define FIXED_HPP

    #include <iostream>

    class Fixed
    {
        public:
            Fixed( void );
            ~Fixed( void );
            Fixed(Fixed const &copy);
            Fixed & operator=(Fixed const &op);
            
            int getRawBits( void ) const;
            void setRawBits( int const raw );
        
        private:
            int _n;
            const static int _bits = 8;

    }; 

#endif