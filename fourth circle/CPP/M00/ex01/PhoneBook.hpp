/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 11:24:44 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOOK_HPP
# define PHONEBOOOK_HPP
#   include "Contact.hpp"
#   include <string>
#   include <stdlib.h>
#   include <iomanip>
#   include <iostream>

class PhoneBook {

public :

    PhoneBook();
    void add_contact();
    bool search();
    void print_index() const;
    ~PhoneBook();

private :

    void print_first();
    std::string replace(std::string key);
    std::string is_empty();
    int value_index(int i, int choice);
    Contact contact[8];
    int _max_contact;
};

#endif