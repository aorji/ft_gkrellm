/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:30:58 by aorji             #+#    #+#             */
/*   Updated: 2018/10/13 13:30:59 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gkrellm.hpp"
#include "sdl.hpp"
Sdl *OS = nullptr;

int main() {

	std::string command;
	std::cout << "(NCurses / SDL): ";
	if (!std::getline(std::cin, command))
		return 0;
	if (command == "NCurses") {
		try { 
			Window wn;
			wn.run();
		}
		catch (std::exception & e) 	{
			std::cout << e.what() << std::endl;
		}
		return 0;
	}
	else if (command == "SDL") {
		OS = new Sdl();

		OS->init("ft_gkrellm", 200, 200, 1000, 500, false);
		while (OS->running())
		{
			OS->handleEvents();
			OS->update();
		}
	
			OS->clean();
	}
	return (0);
}
