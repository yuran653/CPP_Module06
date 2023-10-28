/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:06:08 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/28 18:33:31 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string input) {
	
	
	int			_float_prec = std::numeric_limits<float>::digits10;
	int			_double_prec = std::numeric_limits<double>::digits10;
	int			_int_value;
	char		_char_value;
	float		_float_value;
	double		_double_value;

	while (input.front() == ' ')
		input.erase(0, 1);
	while (input.back() == ' ')
		input.pop_back();

	int len = input.length();
	if (input.back() == 'f') {
		if (len >= 3 && input.compare(len - 3, 3, "inf") == 0) {
			;
		} else {
			input.pop_back();
		}
	}

	std::string	_inf_nan = "undef";
	bool		_defined = false;
	len = input.length();
	if ((len == 3 && (input.compare(len - 3, 3, "nan") == 0))
		|| (len == 4 && (input.compare("+inf") == 0 || input.compare("-inf") == 0))) {
		_inf_nan = input;
		_defined = true;
	} else {
		bool dot = false;
		int	prec = 0;
		int	i = 0;
		if (input.front() == '+' || input.front() == '-')
			i++;
		for (; input[i]; i++) {
			if (isdigit(input[i])) {
				if (dot == true)
					prec++;
			} else if (input[i] == '.') {
				if (dot == true || input.back() == '.')
					throw std::invalid_argument("Invalid input format");
				else
					dot = true;
			} else 
				throw std::invalid_argument("Invalid input format");
		}

		if (prec == 0)
			prec = 1;
		if (prec < std::numeric_limits<float>::digits10)
			_float_prec = prec;
		if (prec < _double_prec)
			_double_prec = prec;

		if (dot == false) {
			_int_value = atoi(input.c_str());
			_char_value = static_cast<char>(_int_value);
			_float_value = static_cast<float>(_int_value);
			_double_value = static_cast<double>(_int_value);
		} else {
			std::istringstream(input) >> _int_value;
			std::istringstream(input) >> std::fixed
				>> std::setprecision(_float_prec) >> _float_value;
			std::istringstream(input) >> std::fixed
				>> std::setprecision(_double_prec) >> _double_value;
			_char_value = static_cast<char>(_int_value);
		}
		// _defined = true;
	}

	// if (_defined == true) {
		if (_inf_nan == "undef") {
			std::string char_string;
			if (_int_value >= 0 && _int_value <= 127 && isprint(_char_value))
				char_string = "char: "
					+ std::string(1, _char_value);
			else
				char_string = "char: Non displayable";
			std::cout << std::fixed << char_string << std::endl
			<< "int: " << _int_value << std::endl
			<< "float: " << std::setprecision(_float_prec) << _float_value << "f" << std::endl
			<< "double: " << std::setprecision(_double_prec) << _double_value << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: " << _inf_nan << "f" << std::endl
			<< "double: " << _inf_nan << std::endl;
		}
	// } else {
	// 	std::cout << "char: undefined" << std::endl
	// 	<< "int: undefined" << std::endl
	// 	<< "float: undefined" << std::endl
	// 	<< "double: undefined" << std::endl;
	// }
}
