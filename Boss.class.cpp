/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 20:20:09 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 20:20:10 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Boss.class.hpp"

Boss::Boss(void)
{
	_x = -1;
	_y = -1;
	_hp = 1;
	_countTime = 0;
	setVis(true);
}

Boss::Boss(int x, int y)
{
	_x = x;
	_y = y;
	_hp = 1;
	setVis(true);
}

Boss::Boss(Boss const &src)
{
	*this = src;
}

Boss & Boss::operator = (Boss const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		_hp = rhs._hp;
		_countTime = rhs._countTime;
		_isVis = rhs._isVis;
	}
	return (*this);
}

Boss::~Boss(void) {}

void Boss::moveBoss()
{
	if (_countTime == 40)
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
