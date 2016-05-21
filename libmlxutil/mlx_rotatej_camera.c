/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotatej_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 03:05:00 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 19:36:54 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

t_mlx_camera	*mlx_rotatej_camera(t_mlx_camera *camera, double angle)
{
	t_fmatrix	tmp;
	double		arr[9];

	tmp.width = 3;
	tmp.height = 3;
	tmp.value = arr;
	ft_bzero(arr, sizeof(arr));
	arr[0] = cos(angle);
	arr[2] = sin(angle);
	arr[4] = 1;
	arr[6] = -sin(angle);
	arr[8] = cos(angle);
	return (mlx_rotate_camera(camera, &tmp));
}
