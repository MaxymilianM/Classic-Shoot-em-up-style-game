/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:48 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 19:44:50 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

#include <iostream>
#include <string>

class Enemy
{
public:
	Enemy(void);
	Enemy(int x, int y);
	~Enemy(void);
	Enemy(Enemy const &src);
	Enemy & operator = (Enemy const & rhs);

	void takeDamage();

	int getX(void) const;
	int getY(void) const;
	int getTime(void) const;
	void setVis(bool vis);
	bool getVis(void) const;
	char getSym(void) const;
	char getColor(void) const;
	void deleteEnemy();
	void move();
	void setXY(int const x, int const y);
	void setHP(int hp);

protected:
	int _x;
	int _y;
	int _hp;
	int _countTime;
	bool _isVis;
	char _sym;
	int _color;

};

#endif
