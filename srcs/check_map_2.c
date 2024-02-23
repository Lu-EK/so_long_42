/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:38:05 by lellong-          #+#    #+#             */
/*   Updated: 2023/07/17 08:38:50 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (&s[i]);
		i--;
	}
	return (NULL);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

bool	has_valid_extension_and_path(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (false);
	if (ft_strcmp(extension, ".ber") != 0)
		return (false);
	return (true);
}

void	check_map_empty(t_data *data, char *buffer)
{
	int		i;
	int		rows;

	i = 0;
	rows = number_of_row(data->filename);
	if (read(data->fd_map, buffer, 1024) == 0)
	{
		ft_printf("Error\nWrong parameters\n");
		if (data->map != NULL)
		{
			while (i < rows)
			{
				free(data->map[i]);
				i++;
			}
			free(data->map);
			free(buffer);
			exit(0);
		}
	}
}
