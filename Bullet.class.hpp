/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:01:22 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 12:22:27 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP
#define BULLET_CLASS_HPP

#include <iostream>
#include <string>

class Bullet
{
public:
	Bullet(void);
	~Bullet(void);
	Bullet(Bullet const &src);
	Bullet & operator = (Bullet const & rhs);

	int getX(void) const;
	int getY(void) const;
	bool getVis(void) const;
	void setVis(bool vis);
	void setXY(int const x, int const y);
	void deleteBull();

protected:
	int _x;
	int _y;
	bool isVis;

};

#endif
