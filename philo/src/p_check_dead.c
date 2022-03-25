/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:38:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:19:08 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checkdead(t_data *data)
{	
	long long	ms;

	ms = current_time_ms();
	if (ms - data->time_last_meal > data->pinfo->time_to_die)
	{
		printf("%lld %d died\n", ms, data->id + 1);
		exit(0);
	}
}
