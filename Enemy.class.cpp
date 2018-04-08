/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:44 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 19:58:42 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(void)
{
	_x = -1;
	_y = -1;
	_hp = 100;
	_countTime = 0;
	setVis(true);
}

Enemy::Enemy(int x, int y)
{
	_x = x;
	_y = y;
	_hp = 100;
	_countTime = 0;
	setVis(true);
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
}

Enemy & Enemy::operator = (Enemy const & rhs)
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


Enemy::~Enemy(void)
{
	std::cout << "Enemy destroit" << std::endl;
}

int Enemy::getX(void) const { return(_x); }
int Enemy::getY(void) const { return(_y); }
int Enemy::getTime(void) const { return _countTime; }
bool Enemy::getVis(void) const { return _isVis; }
void Enemy::setVis(bool vis) { _isVis = vis; }
char Enemy::getSym(void) const { return _sym; }
char Enemy::getColor(void) const { return _color; }
int Enemy::getHP(void) const { return _hp; }
void Enemy::setHP(int hp) { _hp = hp; }

void Enemy::setXY(int const x, int const y)
{
	_x = x;
	_y = y;
}

void Enemy::deleteEnemy()
{
	_x = -1;
	_y = -1;
	_isVis = true;
}

void Enemy::move()
{
	if (_countTime == 15)
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

void    Enemy::takeDamage()
{
	_hp--;
	if (_hp <= 0)
		deleteEnemy();
}
