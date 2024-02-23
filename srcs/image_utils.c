/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:08:21 by lellong-          #+#    #+#             */
/*   Updated: 2023/04/26 14:14:06 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

void	print_image(t_data *data, char *path, int x, int y)
{
	t_image	image;

	image.pointeur_image = mlx_xpm_file_to_image(data->mlx_ptr,
			path, &image.size.x, &image.size.y);
	if (!image.pointeur_image)
	{
		return ;
	}
	image.address = mlx_get_data_addr(image.pointeur_image,
			&image.bits_per_pixel, &image.line_length, &image.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		image.pointeur_image, x, y);
	mlx_destroy_image(data->mlx_ptr, image.pointeur_image);
}
