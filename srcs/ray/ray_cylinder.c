/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:29:01 by lpradene          #+#    #+#             */
/*   Updated: 2024/01/10 12:32:18 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_hit	ray_cylinder_intersection(t_obj *obj, t_ray r)
{
	t_hit	h1;
	t_hit	h2;

	h1 = ray_curves_intersection(obj, r);
	h2 = ray_caps_intersection(obj, r);
	if (h1.distance > 0 && (h1.distance < h2.distance || h2.distance < 0))
		return (h1);
	if (h2.distance > 0 && (h2.distance < h1.distance || h1.distance < 0))
		return (h2);
	return (miss_ray());
}
