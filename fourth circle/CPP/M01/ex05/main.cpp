/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 13:17:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
   
    int life = 10;

    while (life)
    {
        harl.complain("DEBUG");
        harl.complain("WARNING");
        harl.complain("INFO");
        harl.complain("ERROR");
        std::cout << "--------" <<std::endl;
        life--;
    }
    
    return (0);
}