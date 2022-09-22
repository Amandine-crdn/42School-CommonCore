/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 13:34:03 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            int ft_power2(int i, int power);

        private:
            int _n;
            const static int _bits = 8;
    }; 

std::ostream &operator<<(std::ostream &op, const Fixed &a);

#endif