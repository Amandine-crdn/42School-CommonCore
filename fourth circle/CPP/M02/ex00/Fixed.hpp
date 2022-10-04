/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 11:57:33 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

    #include <iostream>

    class Fixed
    {
        public:
            Fixed( void );
            ~Fixed( void );
            Fixed( Fixed const &copy );
            Fixed & operator=( Fixed const &op );
            
            int getRawBits( void ) const;
            void setRawBits( int const raw );
        
        private:
            int _n;
            const static int _bits = 8;

    }; 

#endif