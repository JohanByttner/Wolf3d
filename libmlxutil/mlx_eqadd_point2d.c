/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqadd_point2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 22:48:53 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/16 18:32:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_point		*mlx_eqadd_point2d(t_point *restrict p1, t_point *restrict p2)
{
	p1->i += p2->i;
	p1->j += p2->j;
	return (p1);
}
