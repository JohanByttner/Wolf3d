/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:50:46 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/21 19:59:13 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define FLOOR_HEIGHT -2
# define MAX_OBJSIZE 10
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include "libft.h"
# include "libmlxutil.h"


typedef struct	s_robj
{
	size_t		size;
}				t_robj;

typedef struct	s_collision
{
	t_robj		*obj;
	t_3dpoint	pos;
	double		length;
}				t_collision;

typedef struct	s_map
{
	size_t		size[2];
	t_robj	*data;
}				t_map;

t_map			*map(void);
t_collision		raycast(t_3dpoint *pos, t_3dpoint direction, t_map *m);
t_colour		colour_hit(t_collision c, double div);

#endif

