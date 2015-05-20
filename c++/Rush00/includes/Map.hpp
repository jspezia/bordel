/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:26:33 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/11 16:36:18 by fyadaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "starwars.hpp"
# include "MapObject.hpp"
# include "XWing.hpp"

class Map
{
public:
	Map(XWing  *player, int up, int down, int width);
	Map(Map const &map);
	~Map(void);
	Map			&operator=(Map const &rhs);
	Map			&operator++(void);
	Map			operator++(int);

	int			getUp(void) const;
	int			getDown(void) const;
	std::string	getLook1(void) const;
	std::string	getLook2(void) const;
	std::string	getLook3(void) const;
	int			getWidth(void) const;
	int			getFrame(void) const;
	void		setFrame(int const nb);
	XWing 	*	getPlayer(void) const;
	void		display(void);
	void		addEnemy(void);
	void		updateXWingPos(XWing const &ref);

public:
	static e_game		getStatus(void);
	static void			setStatus(e_game val);

private:

	std::string	_look1;
	std::string	_look2;
	std::string	_look3;
	int			_up;
	int			_down;
	int			_width;
	int			_frame;
	MapObject 	*_obstacles[11];
	int			_collision[11][2];
	XWing		*_player;

	static e_game _status;

};

#endif /* !MAP_HPP */
