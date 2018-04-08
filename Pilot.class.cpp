/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pilot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:31 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 18:03:13 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pilot.class.hpp"

Pilot::Pilot(void) {}

Pilot::Pilot(int x, int y, int winX)
{
	_x = x;
	_y = y;
	_hp = 10;
	_winX = winX - 1;
}

Pilot::~Pilot(void) 
{
	std::cout << "Pilot destroit" << std::endl;
}

int Pilot::getX(void) const
{
	return(_x);
}

int Pilot::getY(void) const
{
	return(_y);
}

void Pilot::setXY(int const x, int const y)
{
	_x = x;
	_y = y;
}

int Pilot::getHP(void) const
{
	return(_hp);
}

void    Pilot::takeDamage()
{
    this->_hp--;
}

Pilot::Pilot(Pilot const &src)
{
	*this = src;
}

Pilot & Pilot::operator = (Pilot const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		_hp = rhs._hp;
		_winX = rhs._winX;
	}
	return (*this);
}
