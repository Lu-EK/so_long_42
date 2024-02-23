/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:58:39 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/03 18:19:05 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//

#ifndef PLAYER_MOVEMENT_H
# define PLAYER_MOVEMENT_H

# define WIDTH 1000
# define HEIGHT 1000
# define SIZE 20
# define SW 50
# define SH 50
# define IM_0 "assets/parquet.xpm"
# define IM_1 "assets/touchebleu.xpm"
# define IM_C "assets/collectible.xpm"
# define IM_E "assets/HOF.xpm"
# define IM_P "assets/CP3.xpm"
# define IM_WE "assets/CP3-WE.xpm"

int		player_moves_right(t_data *data);
int		player_moves_left(t_data *data);
int		player_moves_up(t_data *data);
int		player_moves_down(t_data *data);
int		player_moves_to_exit(t_data *data);

#endif