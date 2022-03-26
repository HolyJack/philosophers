/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:33 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 19:20:01 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_data *data)
{
	printf("%lld %d is eating\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	data->time_last_meal = current_time_ms();
	p_usleep(data, data->pinfo->time_to_eat);
	if (data->times_must_eat > 0)
		data->times_must_eat--;
}
