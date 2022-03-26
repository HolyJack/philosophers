/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 13:42:04 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_data *data)
{
	printf("%lld %d is sleeping\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	release_forks(data);
	p_usleep(data, data->pinfo->time_to_sleep);
}
