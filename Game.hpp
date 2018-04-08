/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:51:29 by pprivalo          #+#    #+#             */
/*   Updated: 2018/04/08 20:01:05 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_HPP
# define _GAME_HPP
# include <ncurses.h>
# include <string>
#include "Pilot.class.hpp"
#include "Enemy.class.hpp"
#include "Asteroids.class.hpp"
#include "Dron.class.hpp"
#include "Stars.class.hpp"
#include "Boss.class.hpp"

class		Game
{
private:
	WINDOW		*_win;
	Pilot		_pilot;
	Bullet		*_bullets;
	Bullet		*_eBullets;
	int			_width;
	int			_height;
	bool		_isRunning;
	bool		_isGameOver;
	int			_score;
	Asteroids	*_aster;
	Dron		*_drons;
	Boss		*_boss;
	Stars		*_stars;
	int			_enemyNbr;
	int			_counter;
	clock_t		t;

	void	render();
	void	keyboardHook();
	void	tryKill(Asteroids *enemy, int i);
	void	tryKill(Dron *enemy, int i);
	void	tryKill(Boss *enemy, int i);
	void	tryKill(int i);
	void	moveBullet(int i);
	void	moveEBullet(int i);
	void	moveEnemy(Asteroids *enemy);
	void	moveEnemy(Dron *enemy);
	void	moveEnemy(Boss *enemy);
	void	moveStar(Stars *star);
	void	createStar(Stars *star);
	void	createBullet();
public:
	Game();
	Game(int w, int h);
	Game(Game const &game);
	~Game();
	
	void	setWidth(int const w);
	void	setHeight(int const h);
	void	game();
	void	attack();
	void	createEnemy(Asteroids *enemy);
	void	createEnemy(Dron *enemy);
	void	createEnemy(Boss *enemy);
	void	gameOver();

	Game & operator = (Game const & rhs);
};

#endif
