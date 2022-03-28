/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 17:14:52 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_data *data)
{
	long long	sleepstart;

	sleepstart = current_time_ms();
	printf("%lld %d is sleeping\n",
		sleepstart - data->pinfo->time_start, data->id + 1);
	release_forks(data);
	p_usleep(data,
		data->pinfo->time_to_sleep - (current_time_ms() - sleepstart));
}
