/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:19 by pprivalo          #+#    #+#             */
/*   Updated: 2018/04/08 20:11:03 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string>
#include "Game.hpp"

int		main(void)
{
	std::string		mesg = "GAME OVER";
	int				row, col;
	Game			game;

	if (initscr())
    {
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(4, COLOR_YELLOW, COLOR_BLACK);
		init_pair(5, COLOR_RED, COLOR_RED);
		getmaxyx(stdscr, row, col);
		game = Game(col, row);
        curs_set(0);
        cbreak();
        noecho();

		game.game();
    }
    else
		std::cerr << "ncurses initialization error" << std::endl;
	return 0;
}
