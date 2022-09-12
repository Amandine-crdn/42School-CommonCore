/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:22:19 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/12 11:10:34 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    std::string new_arg;
    std::string::iterator it;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            new_arg = argv[i];
            for(it = new_arg.begin(); it < new_arg.end(); it++)
                std::cout <<  (char)std::toupper(*it);
        }
        std::cout << std::endl;
    }
    return (0); 
}