/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_think.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:40 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 12:24:47 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_think(t_data	*data)
{
	printf("%lld %d is thinking\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
}
