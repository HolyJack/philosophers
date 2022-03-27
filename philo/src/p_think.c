/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_think.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:40 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/27 14:28:33 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	p_time_to_think(t_data *data)
{
	long long	lastmeal;

	lastmeal = current_time_ms() - data->time_last_meal;
	return (data->pinfo->time_to_die - lastmeal - 1);
}

void	p_think(t_data	*data)
{
	printf("%lld %d is thinking\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	p_usleep(data, p_time_to_think(data));
}
