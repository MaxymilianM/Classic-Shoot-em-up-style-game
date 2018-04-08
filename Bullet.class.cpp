/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:18 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 18:06:08 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet(void)
{
	_x = -1;
	_y = -1;
	isVis = false;
}

Bullet::~Bullet(void) {}

int Bullet::getX(void) const
{
	return(_x);
}

int Bullet::getY(void) const
{
	return(_y);
}

bool Bullet::getVis(void) const
{
	return isVis;
}

void Bullet::setVis(bool vis)
{
	isVis = vis;
}

void Bullet::deleteBull()
{
	_x = -1;
	_y = -1;
	isVis = false;
}

void Bullet::setXY(int const x, int const y)
{
	_x = x;
	_y = y;
}

Bullet::Bullet(Bullet const &src)
{
	*this = src;
}

Bullet & Bullet::operator = (Bullet const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		isVis = rhs.isVis;
	}
	return (*this);
}