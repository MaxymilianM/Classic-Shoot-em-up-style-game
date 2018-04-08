/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:26:00 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 19:34:50 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Asteroids.class.hpp"

Asteroids::Asteroids(void) : Enemy()
{
	_color = 4;
	_sym = 'O';
	_hp = 1;
	setVis(true);
}

Asteroids::Asteroids(int x, int y) : Enemy(x, y) {}

Asteroids::~Asteroids(void)
{
	std::cout << "Asteroids destroit" << std::endl;
}

Asteroids::Asteroids(Asteroids const &src)
{
	*this = src;
}

Asteroids & Asteroids::operator = (Asteroids const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		_hp = rhs._hp;
		_size = rhs._size;
	}
	return (*this);
}
