/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:46:50 by lpradene          #+#    #+#             */
/*   Updated: 2024/01/10 12:46:51 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

float	distance(t_vec3 p1, t_vec3 p2)
{
	return (sqrt(powf(p2.x - p1.x, 2.0) + powf(p2.y - p1.y, 2.0) \
	+ powf(p2.z - p1.z, 2.0)));
}
