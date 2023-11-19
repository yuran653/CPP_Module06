/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:06:05 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 13:07:25 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return 1;
	} else {
		try {
			ScalarConverter::convert(argv[1]);
		} catch (std::invalid_argument& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	}
	return 0;
}

// int main (int argc, char* argv[]) {
// 	ScalarConverter converter;
// 	std::cout << "The address of the instance of the ScalarConverter class is: " << &converter << std::endl;
// 	if (argc != 2) {
// 		std::cerr << "Error: Wrong number of arguments" << std::endl;
// 		return 1;
// 	} else {
// 		try {
// 			converter.convert(argv[1]);
// 		} catch (std::invalid_argument& e) {
// 			std::cerr << "Error: " << e.what() << std::endl;
// 			return 1;
// 		}
// 	}
// 	return 0;
// }
