/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:34:08 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/21 15:43:31 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_n);
}

Fixed& Fixed::operator=(Fixed const &op)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&op != this)
        _n = op.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    _n = raw;
}

//ex01

Fixed::Fixed(int const n_const) //left shift operator
{ 
     if (n_const > 8388607 || n_const < -8388608)
        throw std::runtime_error("failed to construct");
    else
        _n = n_const << _bits;

    std::cout << "Fixed::Fixed(int const n_const)" << std::endl;
    _n = n_const << _bits; //3328 decimal, et 101100000000 en binaire, 13(10) 1101(2)
    std::cout << _n << std::endl;
}

Fixed::Fixed(float const float_const)
{
     if (float_const > 8388607.0f || float_const < -8388608.0f)
        throw std::runtime_error("failed to construct");
    else
       _n = (int)roundf(float_const * (1 << _bits));

    std::cout << "Fixed::Fixed(float const float_const)" << std::endl;
    _n = (int)roundf(float_const * (1 << _bits)); //2^8 = 256 precision
    std::cout << _n << std::endl;
}

float Fixed::toFloat( void ) const
{
    std::cout << "float Fixed::toFloat( void ) const" << std::endl;
    std::cout << (float)_n / (float)(1 << _bits) << std::endl;
    return ((float)_n / (float)(1 << _bits));
}

int Fixed::toInt( void ) const
{
    std::cout << "int Fixed::toInt( void ) const" << std::endl;
    std::cout << (int)(_n >> _bits) << std::endl;
    return ((int)(_n >> _bits));
}

std::ostream &operator<<(std::ostream &op, const Fixed  &a)
{
	op << a.toFloat();
	return (op);
}