/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 11:24:44 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook repertoire;
    std::string input;

    std::cout << "Opened" << std::endl;
    while (1)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD")
            repertoire.add_contact();
        else if (input == "SEARCH")
        {
            if (repertoire.search() == false)
                std::cerr << "Error : you havn't contact" << std::endl;
            else
                repertoire.print_index();
        }
        else if (input == "EXIT" || std::cin.eof())
        {
            std::cout << "Closed" << std::endl;
            break ;
        }
    }
    return (0);
}
