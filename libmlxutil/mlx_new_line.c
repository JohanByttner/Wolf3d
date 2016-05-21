/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:41:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 18:34:12 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "libft.h"

t_3dline	*mlx_new_line(t_3dpoint *p1, t_3dpoint *p2)
{
	t_3dline	*line;

	if (!(line = ft_memalloc(sizeof(t_3dline))))
		return (0);
	if (!(mlx_init_line(line, p1, p2)))
	{
		free(line);
		return (0);
	}
	return (line);
}
