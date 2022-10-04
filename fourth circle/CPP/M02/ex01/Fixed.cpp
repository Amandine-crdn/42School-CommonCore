/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:34:08 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 13:35:48 by acerdan          ###   ########.fr       */
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
    return (this->_n);
}

Fixed& Fixed::operator=(Fixed const &op)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&op != this)
        this->_n = op.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    this->_n = raw;
}

//ex01

int Fixed::ft_power2(int i, int power){
    int res = 1;

    for(int y = 0; y < power; y++)
        res *= i;
    return (res);
}

Fixed::Fixed(int const n_const)
{ 
    std::cout << "Int constructor called" << std::endl;
    if (n_const > 8388607 || n_const < -8388608)
    {
        std::cout << "no permission to use this value" << std::endl;
        exit(-1);
    }
    else
        this->_n = n_const * ft_power2(2, _bits);
}

Fixed::Fixed(float const float_const)
{
    std::cout << "Float constructor called" << std::endl;
    if (float_const > 8388607.0f || float_const < -8388608.0f)
    {
        std::cout << "no permission to use this value" << std::endl;
        exit(-1);
    }
    else
      this-> _n = (int)roundf(float_const * ft_power2(2, _bits));
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_n / (float)(1 << _bits));
}

int Fixed::toInt( void ) const
{
    return ((int)(this->_n / 256));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}