/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:34:08 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 13:47:54 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0)
{
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed(Fixed const &copy)
{
    *this = copy;
}

int Fixed::getRawBits( void ) const
{
    return (this->_n);
}

Fixed& Fixed::operator=(Fixed const &op)
{
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
    if (n_const > 8388607 || n_const < -8388608)
        exit(-1);
    else
        this->_n = n_const * ft_power2(2, _bits);
}

Fixed::Fixed(float const float_const)
{
    if (float_const > 8388607.0f || float_const < -8388608.0f)
        exit(-1);
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ex02
//comparaison operator
bool Fixed::operator>(Fixed const &op) 
{
    if (this->_n > op._n)
        return (true);
    return (false);   
}
bool Fixed::operator<(Fixed const &op) 
{
    if (this->_n < op._n)
        return (true);
    return (false);
}
bool Fixed::operator<=(Fixed const &op) 
{
    if (this->_n <= op._n)
        return (true);
    return (false);
}
bool Fixed::operator>=(Fixed const &op) 
{
    if (this->_n >= op._n)
        return (true);
    return (false);
}
bool Fixed::operator==(Fixed const &op) 
{
    if (this->_n == op._n)
        return (true);
    return (false);
}
bool Fixed::operator!=(Fixed const &op) 
{
    if (this->_n != op._n)
        return (true);
    return (false);
}

//arithmetie operator
Fixed  Fixed::operator+(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits(((this->getRawBits() + op.getRawBits())) / 256);
    return (fixed);
}
Fixed  Fixed::operator-(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits((this->getRawBits() - op.getRawBits()) >> this->_bits);
    return (fixed);
}
Fixed  Fixed::operator*(Fixed const &op)
{
    Fixed fixed = *this;
   
    fixed.setRawBits((this->getRawBits() * op.getRawBits()) / ft_power2(2, _bits));
    return (fixed);
}
Fixed  Fixed::operator/(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits((this->getRawBits() / op.getRawBits()) >> (1 * this->_bits));
    return (fixed);
}

//incrementation and decrementation post et pre
Fixed& Fixed::operator++( void )
{
	++this->_n;
	return (*this);
}
Fixed Fixed::operator++( int )
{
    Fixed fixed = *this;
    ++*this;
	return (fixed);
}

Fixed& Fixed::operator--( void )
{
	--this->_n;
	return (*this);
}
Fixed Fixed::operator--( int )
{
    Fixed fixed = *this;
    --*this;
	return (fixed);
}

//min
Fixed&  Fixed::min(Fixed &op1, Fixed &op2)
{
    if (op1._n < op2._n)
        return (op1);
    return (op2);
}
const Fixed&  Fixed::min(Fixed const &op1, Fixed const &op2)
{
    if (op1._n < op2._bits)
        return (op1);
    return (op2);
}

//max
Fixed & Fixed::max(Fixed &op1, Fixed &op2)
{
    if (op1._n > op2._bits)
        return (op1);
    return (op2);
}
Fixed const & Fixed::max(Fixed const &op1, Fixed const &op2)
{
    if (op1._n > op2._bits)
        return (op1);
    return (op2);
}
