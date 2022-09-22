/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 11:24:44 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _max_contact(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::is_empty()
{
    std::string input;

    while (std::getline(std::cin, input) && input.empty())
        ;
    if (std::cin.eof() == true)
        exit(-9);
    return (input);
}

int PhoneBook::value_index(int i, int choice)
{  
    if (choice == 0)
    {
        if (i == 8)
            return(0);
        else
            return (i);
    }
    else if (choice == 1)
    {
        if (i < 8 && _max_contact < 8)
        {
            _max_contact++;
            i++;
        }
        else if (i < 8 && _max_contact == 8)
            i++;
    }
    return (i);
}

void PhoneBook::add_contact()
{
    std::string input;
    static int i = _max_contact;

    i = value_index(i, 0);
    
    std::cout << "1.Tape firstname" << std::endl;
    contact[i].setFirstname(is_empty());

    std::cout << "2.Tape lastname" << std::endl;
    contact[i].setLastname(is_empty());

    std::cout << "3.Tape nickname" << std::endl;
    contact[i].setNickname(is_empty());

    std::cout << "4.Tape phone number" << std::endl;
    contact[i].setPhone(is_empty());

    std::cout << "5.Tape dark secret" << std::endl;
    contact[i].setSecret(is_empty());

    i = value_index(i, 1);
}

void PhoneBook::print_first()
{    
    std::cout << std::setw(10) << "index" << "|"
    << std::setw(10) << "firstname" << "|"
    << std::setw(10) << "lastname" << "|"
    << std::setw(10) << "nickname" << std::endl;
}

std::string PhoneBook::replace(std::string key)
{
    std::string new_word;

    new_word = key.substr(0, 10);
    new_word = new_word.replace(9, 1, ".");
    return (new_word);
}

bool PhoneBook::search()
{
    if (_max_contact == 0)
        return (false);
    print_first();
    for(int y = 0; y < _max_contact; y++)
    {
        std::string temp_firstname(contact[y].getFirstname());
        std::string temp_lastname(contact[y].getLastname());
        std::string temp_nickname(contact[y].getNickname());

        if (contact[y].getFirstname().size() >= 10)
            temp_firstname = replace(temp_firstname);
        if (contact[y].getLastname().size() >= 10)
            temp_lastname = replace(temp_lastname);
        if (contact[y].getNickname().size() >= 10)
            temp_nickname = replace(temp_nickname);
        std::cout << std::setw(10) << y << "|" << std::setw(10) << temp_firstname << "|" <<
        std::setw(10) << temp_lastname << "|" << std::setw(10) << temp_nickname << std::endl;
    }
    return (true);
}

void PhoneBook::print_index() const
{
    int index;
    
    std::cout << "Choice index to print" << std::endl;
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cout << "Not an int\n" << std::endl;
        exit (-9);
    }
    else
    {
        if (index >= 0 && index <= 8 && index < _max_contact)
        {
            std::cout << "Firstname: " << contact[index].getFirstname() << std::endl;
            std::cout << "Lastname: " + contact[index].getLastname() << std::endl;    
            std::cout << "Nickname: " + contact[index].getNickname() << std::endl;  
            std::cout << "Phone Number: " + contact[index].getPhone() << std::endl;   
            std::cout << "Darkest Secret: " + contact[index].getSecret() << std::endl;    
        }
        else
            std::cout << "Contact doesn't exists" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}
