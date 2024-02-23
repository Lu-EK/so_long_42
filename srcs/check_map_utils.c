/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:05:31 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/28 14:23:44 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

char	**copy_map(t_data *data)
{
	int	i;

	i = 0;
	data->verif_map = malloc(sizeof(char *)
			* (number_of_row(data->filename) + 1));
	if (!data->verif_map)
		return (NULL);
	while (i < number_of_row(data->filename))
	{
		data->verif_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	get_player_position(data);
	return (data->verif_map);
}

void	free_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (i < number_of_row(data->filename))
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
	return ;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (!str)
		return ;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	output = malloc(count * size);
	if (output == 0)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*string;
	int		size;

	i = 0;
	size = ft_strlen(&src[0]);
	string = NULL;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
