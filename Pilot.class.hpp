/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pilot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:35 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 17:59:43 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILOT_CLASS_HPP
#define PILOT_CLASS_HPP

#include <iostream>
#include <string>

#include "Bullet.class.hpp"

class Pilot
{
public:
	Pilot(void);
	Pilot(int x, int y, int winX);
	~Pilot(void);
	Pilot(Pilot const &src);
	Pilot & operator = (Pilot const & rhs);
	void takeDamage();
	
	int getX(void) const;
	int getY(void) const;
	void setXY(int const x, int const y);
	
	int getHP(void) const;
	
protected:
	int _x;
	int _y;
	int _hp;
	int	_winX;
	
};

#endif
