/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/16 07:46:25 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
Weapon::Weapon()
{

}

Weapon init("flower");

Weapon::Weapon( std::string type ) : _type(type)
{

}

Weapon::~Weapon()
{

}

std::string const & Weapon::getType() const
{
    return(_type);
}

void Weapon::setType( std::string new_type )
{
    this->_type = new_type;
}
