/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dron.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:08:17 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 19:37:24 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dron.class.hpp"

Dron::Dron(void) : Enemy()
{
	_color = 3;
	_sym = '<';
	_hp = 3;
	setVis(true);
}

Dron::Dron(int x, int y) : Enemy(x, y) {}

Dron::~Dron(void)
{
	std::cout << "Asteroids destroit" << std::endl;
}

Dron::Dron(Dron const &src)
{
	*this = src;
}

Dron & Dron::operator = (Dron const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		_hp = rhs._hp;
	}
	return (*this);
}
