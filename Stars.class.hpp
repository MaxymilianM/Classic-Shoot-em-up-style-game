/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:15:08 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 16:15:09 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_CLASS_HPP
#define STARS_CLASS_HPP

#include <iostream>
#include <string>

class Stars
{
public:
	Stars(void);
	Stars(int x, int y);
	~Stars(void);
	Stars(Stars const &src);
	Stars & operator = (Stars const & rhs);


	int getX(void) const;
	int getY(void) const;
	int getTime(void) const;
	
	void setVis(bool vis);
	bool getVis(void) const;
	
	void deleteStars();
	
	void move();

	void setXY(int const x, int const y);

protected:
	int _x;
	int _y;
	int _hp;
	int _countTime;
	bool _isVis;

};

#endif
