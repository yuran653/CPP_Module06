/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:06:08 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 13:23:25 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

static void	setPrecision(int* prec, int* float_prec, int* double_prec) {
	if (*prec == 0)
		*prec = 1;
	if (*prec < *float_prec)
		*float_prec = *prec;
	if (*prec < *double_prec) 
		*double_prec = *prec;
}

static std::string	definePrecType(std::string input, int* float_prec, int* double_prec) {
	std::string inf_nan = "undef";
	int len = input.length();
	if ((len == 3 && ((input.compare("nan") == 0) || (input.compare("inf") == 0)))
		|| (len == 4 && (input.compare("+inf") == 0 || input.compare("-inf") == 0)))
		return input;
	bool dot = false;
	int	prec = 0;
	int	i = 0;
	if (input.front() == '+' || input.front() == '-')
		i++;
	for (; input[i]; i++) {
		if (isdigit(input[i])) {
			if (dot == true)
				prec++;
		} else if (i != 0 && input[i] == '.') {
			if (dot == true || input.back() == '.')
				throw std::invalid_argument("Invalid input format");
			else
				dot = true;
		} else 
			throw std::invalid_argument("Invalid input format");
	}
	setPrecision(&prec, float_prec, double_prec);
	return inf_nan;
}

static std::string trimInput(std::string* input) {
	while (input->front() == ' ')
		input->erase(0, 1);
	while (input->back() == ' ')
		input->pop_back();
	if (input->back() == 'f' && input->compare("inf") != 0) {
		if (input->length() == 4 && input->compare(1, 3, "inf") == 0) {
			return *input;
		} else {
			input->pop_back();
		}
	}
	return *input;
}

void	ScalarConverter::convert(std::string input) {
	if (input.length() == 0)
		throw std::invalid_argument("Invalid input format");
	int float_prec = std::numeric_limits<float>::digits10;
	int double_prec = std::numeric_limits<double>::digits10;
	std::string inf_nan = definePrecType(trimInput(&input), &float_prec, &double_prec);

	if (inf_nan == "undef") {
		double double_value;
		std::istringstream(input) >> double_value;
		int int_value = static_cast<int>(double_value);
		char char_value = static_cast<char>(double_value);
		float float_value = static_cast<float>(double_value);
		std::string char_string;
		if (int_value >= 0 && int_value <= 127 && isprint(char_value))
			char_string = "char: " + std::string(1, char_value);
		else
			char_string = "char: Non displayable";
		std::cout
		<< char_string << std::endl << "int: " << int_value << std::endl << std::fixed
		<< "float: " << std::setprecision(float_prec) << float_value << "f" << std::endl
		<< "double: " << std::setprecision(double_prec) << double_value << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << inf_nan << "f" << std::endl
		<< "double: " << inf_nan << std::endl;
	}
}
