/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:33 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:46:43 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_data *data)
{
	grab_forks(data);
	printf("%lld %d is eating\n",
		current_time_ms(), data->id + 1);
	data->time_last_meal = current_time_ms();
	usleep(data->pinfo->time_to_eat * 1000);
	release_forks(data);
}
