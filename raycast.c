/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 23:45:01 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/20 23:28:09 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
/*
** Simplest method possible
*/

t_collision	raycast(t_3dpoint *org, t_3dpoint dir, t_map *m)
{
	t_collision	res;
	t_3dpoint	pos;
	double		t[2];

	mlx_copy_point(&pos, org);
	while (0 < pos.i && pos.i < m->size[0]
		&& 0 < pos.j && pos.j < m->size[1])
	{
		mlx_eqadd_point(&pos, &dir);
	}
	if (0 < pos.i && pos.i < m->size[0]
		&& 0 < pos.j && pos.j < m->size[1])
		;
	else
	{
		t[0] = (0 < pos.i && pos.i < m->size[0]) ? 0 : 
			fmod(fabs(pos.i), m->size[0]);
		t[1] = (0 < pos.j && pos.j < m->size[1]) ? 0 : 
			fmod(fabs(pos.j), m->size[1]);
		t[0] = (t[0] == 0 || dir.i == 0) ? 0 : t[0] / fabs(dir.i);
		t[1] = (t[1] == 0 || dir.j == 0) ? 0 : t[1] / fabs(dir.j);
		//printf("times %lf %lf}}dir [%lf] [%lf]", t[0], t[1], dir.i, dir.j);
		mlx_eqsub_point(&pos, mlx_eqmul_point(&dir, fmax(t[0], t[1])));
	}
	mlx_copy_point(&(res.pos), &pos);
	res.obj = 0;
	mlx_eqsub_point(&pos, org);
	res.length = mlx_abs_point2d((t_point *)&pos);
	return (res);
}
