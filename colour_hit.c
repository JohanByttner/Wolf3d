/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:07:57 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/21 19:59:44 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_colour	colour_hit(t_collision c, double angle)
{
	t_colour	colour;

	colour = (t_colour){ 0, 0, 0, 0 };
	colour.green = fmin(CHAR_MAX, 1440 * cos(angle) / c.length + 1);
	return (colour);
}
