/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 20:20:04 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 20:20:06 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_CLASS_HPP
#define BOSS_CLASS_HPP

#include "Enemy.class.hpp"

class Boss : virtual public Enemy
{
public:
	Boss(void);
	Boss(int x, int y);
	~Boss(void);
	Boss(Boss const &src);
	Boss & operator = (Boss const & rhs);

	void moveBoss();

};

#endif

