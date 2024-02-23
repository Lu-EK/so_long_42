/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:57:00 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/29 16:39:10 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

bool	is_map_valid(char **map, int hauteur, int longueur);
bool	is_map_valid2(t_data *data, int l, int m);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
char	**copy_map(t_data *data);
int		all_valid(t_data *data, char *filename);
void	free_map(t_data *data, char **map);
void	fill_arrays(t_data *data);
int		has_valid_path(t_data *data, int row, int col, int i);
char	*ft_strdup(const char *src);
bool	has_valid_extension_and_path(char *filename);
void	check_map_empty(t_data *data, char *buffer);
bool	do_map_file_exists(char *filename);
void	get_player_position(t_data *data);
bool	is_parsing_valid(char c);

#endif