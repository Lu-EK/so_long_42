/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:53:42 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/03 18:21:40 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

char	**file_to_array(t_data *data);
void	draw_board(char **board, t_data *data, int y, int x);
char	**malloc_tableau(t_data *data, char **map);
void	print_map_terminal(t_data *data, char **map);
void	count_collectibles(t_data *data);
int		number_of_col(char *filename);
void	raccourcisseur(char buffer, t_data data, int i);
int		number_of_row(char *filename);
char	**get_array(char *filename, t_data *data);
void	read_map(t_data *data, char *buffer, int x, int y);

#endif