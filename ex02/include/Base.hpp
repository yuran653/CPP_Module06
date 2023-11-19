/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:25:36 by jgoldste          #+#    #+#             */
/*   Updated: 2023/11/19 15:16:25 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

class NullBase {};

class Base {
	public:
		virtual ~Base();

		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
