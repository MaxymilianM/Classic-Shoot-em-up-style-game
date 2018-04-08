/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:15:12 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 16:52:24 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Stars.class.hpp"

Stars::Stars(void)
{
	_x = 1;
	_y = 1;
	_hp = 100;
	_countTime = 0;
	setVis(true);
}

Stars::Stars(int x, int y)
{
	_x = x;
	_y = y;
	_hp = 100;
	_countTime = 0;
	setVis(true);
}

Stars::Stars(Stars const &src)
{
	*this = src;
}

Stars & Stars::operator = (Stars const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		_countTime = rhs._countTime;
		_isVis = rhs._isVis;
	}
	return (*this);
}


Stars::~Stars(void) {}

int Stars::getX(void) const { return(_x); }
int Stars::getY(void) const { return(_y); }
int Stars::getTime(void) const { return _countTime; }
bool Stars::getVis(void) const { return _isVis; }
void Stars::setVis(bool vis) { _isVis = vis; }

void Stars::setXY(int const x, int const y)
{
	_x = x;
	_y = y;
}

void Stars::deleteStars()
{
	_x = -1;
	_y = -1;
	_isVis = false;
}

void Stars::move()
{
	if (_countTime == 3)
	{
		_countTime = 0;
		if (!_isVis)
			_x -= 1;
		else
			_x = -1;
	}
	else
		_countTime++;
}
