/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:06:36 by lellong-          #+#    #+#             */
/*   Updated: 2023/07/15 20:25:16 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h> 
# include "../deps/image.h"
# include "../deps/end_game.h"
# include "../deps/check_map.h"
# include "../deps/image.h"
# include "../deps/map.h"
# include "../deps/itoa.h"
# include "../deps/hooks.h"
# include "../deps/player_movement.h"
# include "../deps/player_movement_2.h"

# define WINDOW_CLOSED 17
# define MAX_WINDOW	4000

int	end(t_data *data);
int	start_game(t_data *data, int argc, char **argv);

#endif