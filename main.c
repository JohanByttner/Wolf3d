/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:59:56 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/20 23:41:02 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	int			i;
	t_3dpoint	p;
	t_map		*m;
	t_collision	c;
	t_3dpoint	pos = { 9, 9, 0 };
	t_3dpoint	ray;
	t_point		cast;
	t_colour	colour;
	m = map();

	int	k = 0;
	i = -500;
	mlx_set_window(0, 1000, 1000, "Wolf3d");
	mlx_set_image(0, 1000, 1000);
	ray.k = 0;
	//main loop
	while (k < 10000)
	{
	while (i < 500)
	{
		cast.i = i;
		ray.i = cos((i / 2000.0) * M_PI);
		ray.j = sin((i / 2000.0) * M_PI);
		c = raycast(&pos, ray, m);
		//mlx_eqsub_point(&(c.pos), &pos);
//		colour = colour_hit(c, div);
		for (cast.j = -500; cast.j < 500; cast.j++)
		{
			colour = colour_hit(c, cast.j * M_PI / 2000.0);
			mlx_put_point2d_to_image(&cast, mlx_get_image(0), &colour);
		}
		i++;
		//printf("c is |%lf|%lf|%lf|%d\n", c.pos.i, c.pos.j, c.pos.k, colour.green);
	}
	mlx_put_image_to_window(mlx_get_handler()->init, mlx_get_window(0)->window,
		mlx_get_image(0)->image, 0, 0);
	k++;
	if (!(k % 100))
		printf("Fps test, %k = %d\n", k);
}
//sleep(10);
}
