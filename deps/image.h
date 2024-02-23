/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:51:04 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/26 17:16:09 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	char	**map;
	char	**verif_map;
	char	*filename;
	int		collectibles;
	char	last_movement;
	int		fd_map;
	int		m_counter;
	t_coord	p_p;
	int		delta_row[4];
	int		delta_col[4];
}	t_data;

typedef struct s_image
{
	void	*pointeur_image;
	char	*address;
	t_coord	image_position;
	t_coord	size;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

void	print_image(t_data *data, char *path, int x, int y);
void	print_count_panel(t_data *data, int mov);

#endif