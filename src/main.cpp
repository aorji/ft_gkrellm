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

int main() {
	try { 
		Window wn;
		wn.run();
	}
	catch (std::exception & e) 	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
