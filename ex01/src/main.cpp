/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:00:38 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 12:24:03 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
	Data* ptr = new Data;
	uintptr_t serialized = Serializer::serialize(ptr);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << std::endl;
	if (ptr == deserialized && ptr == Serializer::deserialize(serialized)
		&& Serializer::deserialize(serialized) == deserialized
		&& Serializer::serialize(deserialized) == serialized)
		std::cout << "Serialization/deserialization: OK" << std::endl;
	else
		std::cout << "Serialization/deserialization: KO" << std::endl;

	if (static_cast<ptrdiff_t>(ptr - deserialized) == 0)
		std::cout << "Address difference == 0: OK" << std::endl;
	else
		std::cout << "Address differnce != 0: KO" << std::endl;

	ptr->char_value = 42;
	ptr->int_value = 42;
	ptr->float_value = 42.42;
	ptr->double_value = 42.42;
	std::cout << std::endl << "<Data> values set to \'42\' || \'42.42\'" << std::endl
	<< "char value: " << ptr->char_value << std::endl
	<< "int value: " << ptr->int_value << std::endl
	<< "float value: " << ptr->float_value << "f" << std::endl
	<< "double value: " << ptr->double_value << std::endl;

	ptr->char_value++;
	ptr->int_value++;
	ptr->float_value += 0.58;
	ptr->double_value += 0.58;
	std::cout << std::endl << "<Deserialized> values set to \'43\'" << std::endl
	<< "char value: " << deserialized->char_value << std::endl
	<< "int value: " << deserialized->int_value << std::endl
	<< "float value: " << deserialized->float_value << "f" << std::endl
	<< "double value: " << deserialized->double_value << std::endl;

	Serializer::deserialize(serialized)->char_value /= 0.42;
	Serializer::deserialize(serialized)->int_value /= 0.42;
	Serializer::deserialize(serialized)->float_value /= 0.42;
	Serializer::deserialize(serialized)->double_value /= 0.42;
	std::cout << std::endl
		<< "<Serialized -> Deserialized> values set to \'f\' || \'102\' || \'102.381\'"
		<< std::endl
	<< "char value: " << ptr->char_value << std::endl
	<< "int value: " << ptr->int_value << std::endl
	<< "float value: " << ptr->float_value << "f" << std::endl
	<< "double value: " << ptr->double_value << std::endl;
	std::cout << std::endl;
	
	delete ptr;

	return 0;
}
