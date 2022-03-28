/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:38:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 15:08:24 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checkdead(t_data *data)
{	
	long long	ms;

	ms = current_time_ms();
	if (ms - data->time_last_meal >= data->pinfo->time_to_die)
		p_die(ms - data->pinfo->time_start, data);
}
