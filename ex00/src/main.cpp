/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:06:05 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/30 15:29:17 by jgoldste         ###   ########.fr       */
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
// 	ScalarConverter a;
// 	if (argc != 2) {
// 		std::cerr << "Error: Wrong number of arguments" << std::endl;
// 		return 1;
// 	} else {
// 		try {
// 			a.convert(argv[1]);
// 		} catch (std::invalid_argument& e) {
// 			std::cerr << "Error: " << e.what() << std::endl;
// 			return 1;
// 		}
// 	}
// 	return 0;
// }