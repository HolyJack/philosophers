/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_usleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:34:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 18:41:44 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_usleep(t_data *data, long long ms)
{
	const long long	start = current_time_ms();
	long long		cur;

	cur = current_time_ms();
	while (ms > cur - start)
	{
		usleep(100);
		cur = current_time_ms();
		checkdead(data);
	}
}