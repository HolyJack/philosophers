/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:45:25 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_data *data)
{
	p_printstatus(data,
		p_current_time_ms() - data->pinfo->time_start,
		data->id + 1, "is sleeping");
	p_release_forks(data);
	p_usleep(data->pinfo->time_to_sleep);
}
