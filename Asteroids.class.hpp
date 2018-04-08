/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:26:04 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 17:00:48 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASTEROIDS_CLASS_HPP
#define ASTEROIDS_CLASS_HPP

#include "Enemy.class.hpp"

class Asteroids : virtual public Enemy
{
public:
	Asteroids(void);
	Asteroids(int x, int y);
	~Asteroids(void);
	Asteroids(Asteroids const &src);
	Asteroids & operator = (Asteroids const & rhs);
	
protected:
	int _size;

};

#endif
