/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:54:35 by pprivalo          #+#    #+#             */
/*   Updated: 2018/04/08 20:10:16 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
{
	this->_win = newwin(1, 1, 0, 0);
};

Game::Game(int w, int h) : _width(w), _height(h)
{
	this->_win = newwin(this->_height, this->_width, 0, 0);
}

Game::Game(Game const &game)
{
	*this = game;
}

Game::~Game() {}

void	Game::setWidth(int const w) { this->_width = w; }
void	Game::setHeight(int const h) { this->_height = h; }

void	Game::keyboardHook()
{
	const int	key = wgetch(this->_win);

	if (key == 27)
		this->_isRunning = false;
	else if (key == 'w' && _pilot.getY() - 1 > 0)
		_pilot.setXY(_pilot.getX(), _pilot.getY() - 1);
	else if (key == 's' && _pilot.getY() + 1 < this->_height - 1)
		_pilot.setXY(_pilot.getX(), _pilot.getY() + 1);
	else if (key == 'a' && _pilot.getX() - 1 > 0)
		_pilot.setXY(_pilot.getX() - 1, _pilot.getY());
	else if (key == 'd' && _pilot.getX() + 1 < this->_width - 1)
		_pilot.setXY(_pilot.getX() + 1, _pilot.getY());
	if (key == 32)
		this->attack();
}

void	Game::attack()
{
	int		i = -1;

	while (++i < _width)
	{
		if (!_bullets[i].getVis())
		{
			_bullets[i].setVis(true);
			_bullets[i].setXY(_pilot.getX() + 1, _pilot.getY());
			break ;
		}
	}
}

void	Game::gameOver()
{
	int		key;
	mvprintw(_height / 2, (_width - 10) / 2, "GAME OVER!");
	key = getch();
	if (key == 27)
		_isRunning = false;
}

void	Game::createEnemy(Asteroids *enemy)
{
	int		i = -1;
	
	if (clock() % 30 == 15)
		while (++i < _enemyNbr)
		{
			if (enemy[i].getVis())
			{
				enemy[i].setVis(false);
				enemy[i].setXY(_width - 2, clock() % (_height - 2) + 1);
				break ;
			}
	}
}

void	Game::createEnemy(Dron *enemy)
{
	int		i = -1;
	
	if (clock() % 30 == 15)
		while (++i < _enemyNbr)
		{
			if (enemy[i].getVis())
			{
				enemy[i].setVis(false);
				enemy[i].setXY(_width - 2, clock() % (_height - 2) + 1);
				enemy[i].setHP(3);
				break ;
			}
	}
}

void	Game::createEnemy(Boss *enemy)
{
	if (enemy[0].getVis())
	{
		enemy[0].setVis(false);
			enemy[0].setXY(_width - 6, clock() % (_height - 2) + 1);
		enemy[0].setHP(100);
	}
}

void	Game::createStar(Stars *star)
{
	int		i = -1;
	
	if (clock() % 10 == 5)
		while (++i < _enemyNbr)
		{
			if (star[i].getVis())
			{
				star[i].setVis(false);
				star[i].setXY(_width - 2, clock() % (_height - 2) + 1);
				break ;
			}
	}
}

void	Game::tryKill(Asteroids *enemy, int i)
{
	for (int j = 0; j < _enemyNbr; j++)
	{
		if (!enemy[j].getVis() && _bullets[i].getX() == enemy[j].getX() && _bullets[i].getY() == enemy[j].getY())
		{
			enemy[j].takeDamage();
			_bullets[i].deleteBull();
			_score += 10;
		}
	}
}

void	Game::tryKill(Dron *enemy, int i)
{
	for (int j = 0; j < _enemyNbr; j++)
	{
		if (!enemy[j].getVis() && _bullets[i].getX() == enemy[j].getX() && _bullets[i].getY() == enemy[j].getY())
		{
			enemy[j].takeDamage();
			_bullets[i].deleteBull();
			if (enemy[j].getVis())
				_score += 100;
		}
	}
}

void	Game::tryKill(Boss *enemy, int i)
{
		if (!enemy[0].getVis() && _bullets[i].getX() == enemy[0].getX() && (_bullets[i].getY() == enemy[0].getY()
																		|| _bullets[i].getY() == enemy[0].getY() + 1
																		|| _bullets[i].getY() == enemy[0].getY() + 2))
		{
			enemy[0].takeDamage();
			_bullets[i].deleteBull();
			if (enemy[0].getVis())
				_score += 300;
		}
}

void	Game::tryKill(int i)
{
	if (_eBullets[i].getX() == _pilot.getX() && _eBullets[i].getY() == _pilot.getY())
	{
		_pilot.takeDamage();
		_eBullets[i].deleteBull();
	}
}

void	Game::moveBullet(int i)
{
	if (_bullets[i].getVis())
	{
		if (_bullets[i].getX() + 1 >= _width)
			_bullets[i].deleteBull();
		else if (_bullets[i].getY() > 0 && _bullets[i].getX() > 0)
		{
			wmove(this->_win, _bullets[i].getY(), _bullets[i].getX());
			waddch(this->_win, '-' | COLOR_PAIR(2));
			_bullets[i].setXY(_bullets[i].getX() + 1, _bullets[i].getY());
		}
	}
}

void	Game::moveEBullet(int i)
{
	if (_eBullets[i].getVis() == true)
	{
		if (_eBullets[i].getX() - 1 <= 0)
			_eBullets[i].deleteBull();
		else
		{
			wmove(this->_win, _eBullets[i].getY(), _eBullets[i].getX());
			waddch(this->_win, ':' | A_BOLD | COLOR_PAIR(2));
			_eBullets[i].setXY(_eBullets[i].getX() - 1, _eBullets[i].getY());
		}
	}
}

void	Game::moveEnemy(Asteroids *enemy)
{
	for (int i = 0; i < _enemyNbr; i++)
	{
		if (enemy[i].getX() <= 0)
			enemy[i].setVis(true);
		if (!enemy[i].getVis())
		{
			wmove(this->_win, enemy[i].getY(), enemy[i].getX());
			waddch(this->_win, enemy[i].getSym() | A_BOLD | COLOR_PAIR(enemy[i].getColor()));
			if (enemy[i].getX() == _pilot.getX() && enemy[i].getY() == _pilot.getY())
				_isGameOver = true;
		}
		enemy[i].move();
	}
}

void	Game::moveEnemy(Dron *enemy)
{
	for (int i = 0; i < _enemyNbr; i++)
	{
		if (enemy[i].getX() <= 0)
			enemy[i].setVis(true);
		if (!enemy[i].getVis())
		{
			wmove(this->_win, enemy[i].getY(), enemy[i].getX());
			waddch(this->_win, enemy[i].getSym() | A_BOLD | COLOR_PAIR(enemy[i].getColor()));
			if (enemy[i].getX() == _pilot.getX() && enemy[i].getY() == _pilot.getY())
				_isGameOver = true;
		}
		enemy[i].move();
	}
}

void	Game::moveEnemy(Boss *enemy)
{
	int i = 0;
	if (enemy[i].getX() <= 0)
		enemy[i].setVis(true);
	if (!enemy[i].getVis())
	{
		wattron(_win, COLOR_PAIR(2));
		mvwprintw(this->_win, enemy[i].getY(), enemy[i].getX(), "<||");
		mvwprintw(this->_win, enemy[i].getY() + 1, enemy[i].getX(), " ||>");
		mvwprintw(this->_win, enemy[i].getY() + 2, enemy[i].getX(), "<||");
		wattroff(_win, COLOR_PAIR(2));
		if (enemy[i].getX() == _pilot.getX() && enemy[i].getY() == _pilot.getY())
			_isGameOver = true;
	}
	enemy[i].moveBoss();
	enemy[i].setXY(enemy[i].getX(), _pilot.getY() - 1);

}

void	Game::moveStar(Stars *star)
{
	for (int i = 0; i < _enemyNbr; i++)
	{
		if (star[i].getX() <= 0)
			star[i].setVis(true);
		if (!star[i].getVis())
		{
			wmove(this->_win, star[i].getY(), star[i].getX());
			waddch(this->_win, '.');
		}
		star[i].move();
	}
}

void	Game::createBullet()
{
	int		i = -1;
	int		rand = clock() % (20 * 3);

	if (rand < 20)
		while (++i < 20)
		{
			if (!_eBullets[i].getVis())
			{
				_eBullets[i].setVis(true);
				_eBullets[i].setXY(_drons[rand].getX() - 1, _drons[rand].getY());
				break ;
			}
		}
	if (!_boss[0].getVis())
		while (++i < 20)
		{
			if (!_eBullets[i].getVis())
			{
				_eBullets[i].setVis(true);
				_eBullets[i].setXY(_boss[0].getX() - 1, _boss[0].getY() + clock() % 3);
				break ;
			}
		}
}

void	Game::render()
{
	if (clock() % 4)
		createEnemy(_aster);
	else
		createEnemy(_drons);
	if ((_score / 1000) > _counter && _score != 0)
	{
		createEnemy(_boss);
		_counter++;
	}
	createStar(_stars);
	createBullet();
	wclear(this->_win);
	box(this->_win, 0, 0);
	
	this->moveStar(_stars);
	this->moveEnemy(_aster);
	this->moveEnemy(_drons);
	this->moveEnemy(_boss);
	for (int i = 0; i < _width - 1; i++)
	{
		this->moveBullet(i);
		this->tryKill(_aster, i);
		this->tryKill(_drons, i);
		this->tryKill(_boss, i);
	}
	
	for (int i = 0; i < 20; i++)
	{
		this->tryKill(i);
		this->moveEBullet(i);
	}
	wmove(this->_win, _pilot.getY(), _pilot.getX());
	waddch(this->_win, '}' | A_BOLD | COLOR_PAIR(1));
	mvwprintw(this->_win, 0, 2, "[Score: %d]", _score);
	mvwprintw(this->_win, 0, this->_width / 2 - 13, "[Time: %d:%d]", t / 6000000, (t / 100000) % 60);
	mvwprintw(this->_win, 0, this->_width - 19, "[HP: ");
	for (int i = 0; i < 10 - _pilot.getHP(); i++)
		mvwprintw(this->_win, 0, this->_width - 14 + i, " ");
	wattron(_win, COLOR_PAIR(2));
	for (int i = 0; i < _pilot.getHP(); i++)
		mvwprintw(this->_win, 0, this->_width - 4 - this->_pilot.getHP() + i, "|");
	wattroff(_win, COLOR_PAIR(2));
	mvwprintw(this->_win, 0, this->_width - 4, " ]");
	wrefresh(this->_win);
}

void	Game::game()
{
	keypad(_win, true);
	_counter = 0;
	_enemyNbr = (int)((_height * _width) * 0.5);
	_drons = new Dron[_enemyNbr];
	_aster = new Asteroids[_enemyNbr];
	_boss = new Boss[1];
	this->_stars = new Stars[_enemyNbr * 2];
	this->_bullets = new Bullet[40];
	this->_eBullets = new Bullet[_width];
	this->_pilot  = Pilot(1, this->_height / 2, this->_width);
	wtimeout(this->_win, 20);
	this->_score = 0;
	this->_isRunning = true;
	this->_isGameOver = false;
	while (this->_isRunning)
	{
		t = clock();
		if (_isGameOver || _pilot.getHP() <= 0)
			gameOver();
		else
		{
			this->keyboardHook();
			this->render();
		}
	}
	delwin(this->_win);
	delete []_bullets;
	delete []_eBullets;
	delete []_drons;
	delete []_aster;
	delete []_stars;
	delete []_boss;
	endwin();
}

Game & Game::operator = (Game const & rhs)
{
	if (this != &rhs)
	{
		_win = rhs._win;
		_pilot = rhs._pilot;
		_bullets = rhs._bullets;
		_eBullets = rhs._eBullets;
		_width = rhs._width;
		_height = rhs._height;
		_isRunning = rhs._isRunning;
		_isGameOver = rhs._isGameOver;
		_score = rhs._score;
		_aster = rhs._aster;
		_drons = rhs._drons;
		_stars = rhs._stars;
		_enemyNbr = rhs._enemyNbr;
		t = rhs.t;
	}
	return (*this);
}
