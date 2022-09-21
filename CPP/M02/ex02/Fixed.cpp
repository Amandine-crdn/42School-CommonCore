/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:34:08 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/21 15:42:38 by acerdan          ###   ########.fr       */
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
    return (_n);
}

Fixed& Fixed::operator=(Fixed const &op)
{
    if (&op != this)
        _n = op.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    _n = raw;
}

Fixed::Fixed(int const n_const)
{
    if (n_const > 8388607 || n_const < -8388608)
        throw std::runtime_error("failed to construct");
    else
        _n = n_const << _bits;
}

Fixed::Fixed(float const float_const)
{
    if (float_const > 8388607.0f)
        _n = (int)roundf(8388607 * (1 << _bits)); 
    else if (float_const < -8388608.0f)
        _n = (int)roundf(-8388608 * (1 << _bits));
    else
        _n = (int)roundf(float_const * (1 << _bits));
}

int Fixed::toInt( void ) const
{
    return ((int)(_n >> _bits));
}

float Fixed::toFloat( void ) const
{
    return ((float)_n / (float)(1 << _bits));
}

std::ostream &operator<<(std::ostream &op, const Fixed  &a)
{
	op << a.toFloat();
	return (op);
}

//ex02
//comparaison operator
bool Fixed::operator>(Fixed const &op) 
{
    if (_n > op._n)
        return (true);
    return (false);   
}
bool Fixed::operator<(Fixed const &op) 
{
    if (_n < op._n)
        return (true);
    return (false);
}
bool Fixed::operator<=(Fixed const &op) 
{
    if (_n <= op._n)
        return (true);
    return (false);
}
bool Fixed::operator>=(Fixed const &op) 
{
    if (_n >= op._n)
        return (true);
    return (false);
}
bool Fixed::operator==(Fixed const &op) 
{
    if (_n == op._n)
        return (true);
    return (false);
}
bool Fixed::operator!=(Fixed const &op) 
{
    if (_n != op._n)
        return (true);
    return (false);
}

//arithmetie operator
Fixed  Fixed::operator+(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits(this->getRawBits() + op.getRawBits());
    return (fixed);
}
Fixed  Fixed::operator-(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits(this->getRawBits() - op.getRawBits());
    return (fixed);
}
Fixed  Fixed::operator*(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits(this->getRawBits() * op.getRawBits());
    return (fixed);
}
Fixed  Fixed::operator/(Fixed const &op)
{
    Fixed fixed;
   
    fixed.setRawBits(this->getRawBits() / op.getRawBits());
    return (fixed);
}

//incrementation and decrementation post et pre
Fixed& Fixed::operator++( void )
{
    std::cout << "AFTER op ++\n";
	++_n;
	return (*this);
}
Fixed Fixed::operator++( int )
{
    Fixed fixed = *this;
    std::cout << "BEFORE ++ op\n";
    ++*this;
	return (*this);
}

Fixed& Fixed::operator--( void )
{
	--_n;
	return (*this);
}
Fixed Fixed::operator--( int )
{
    Fixed fixed = *this;
    --*this;
	return (*this);
}


//min
int Fixed::min(Fixed &op1, Fixed &op2)
{
    if (op1._n < op2._n)
        return (op1._n);
    return (op2._n);
}
int Fixed::min(Fixed const &op1, Fixed const &op2)
{
    if (op1._n < op2._bits)
        return (op1._n);
    return (op2._n);
}

//max
int Fixed::max(Fixed &op1, Fixed &op2)
{
    if (op1._n > op2._bits)
        return (op1._n);
    return (op2._n);
}
int Fixed::max(Fixed const &op1, Fixed const &op2)
{
    if (op1._n > op2._bits)
        return (op1._n);
    return (op2._n);
}