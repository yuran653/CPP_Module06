/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:40:33 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 16:07:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main() {
	Base *p = NULL;
	std::srand(std::time(0));
	for (int i = 0; i < 10; i++) {
		if (i != 0)
			p = p->generate();
		else
			std::cout << "<Base> pointer is NULL" << std::endl;
		p->identify(p);
		p->identify(*p);
		delete p;
		std::cout << std::endl;
	}
	return 0;
}
