/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:04:29 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/03 18:16:48 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int		handle_keypress(int keysym, t_data *data);
int		handle_no_event(void *data);
int		handle_keyrelease(int keysym, t_data *data);
int		destroy_pointer(t_image *image);
void	handle_keypress_util(int keysym, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);

#endif