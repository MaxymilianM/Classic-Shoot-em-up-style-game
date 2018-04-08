/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dron.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:08:21 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/08 17:00:42 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRON_CLASS_HPP
#define DRON_CLASS_HPP

#include "Enemy.class.hpp"

class Dron : virtual public Enemy
{
public:
	Dron(void);
	Dron(int x, int y);
	~Dron(void);
	Dron(Dron const &src);
	Dron & operator = (Dron const & rhs);
	
};

#endif
