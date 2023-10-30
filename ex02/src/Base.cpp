/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:27:44 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/30 18:37:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

Base::~Base() {
}

Base*	Base::generate(void) {
	switch (rand() % 4) {
		case 0: {
			std::cout << "Generated class A" << std::endl;
			return new A;
		} case 1: {
			std::cout << "Generated class B" << std::endl;
			return new B;
		} case 2: {
			std::cout << "Generated class C" << std::endl;
			return new C;
		} case 3: {
			std::cout << "Generated class D" << std::endl;
			return new D;
		}
	}
	return (NULL);
}

void	Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is identified as class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is identified as class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is identified as class C" << std::endl;
	else
		std::cout << "Pointer is not identified" << std::endl;
}

void Base::identify(Base& p) {
	std::string types[3] = {"A", "B", "C"};
	for (int i = 0; i <=3; i++) {	
		try {
			if (i == 3 || static_cast<Base*>(&p) == NULL) {
				std::cout << "Reference is not identified" << std::endl;
				break;
			} else if (types[i] == "A") {
				(void)dynamic_cast<A&>(p);
			} else if (types[i] == "B") {
				(void)dynamic_cast<B&>(p);  
			} else if (types[i] == "C") {
				(void)dynamic_cast<C&>(p);
			}
			std::cout << "Reference is identified as class " << types[i] << std::endl;
			break;	
		} catch (std::bad_cast& e) {}
	}
}
