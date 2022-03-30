/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:42 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 20:27:32 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_usleep(long long ms)
{
	const long long	start = current_time_ms();
	long long		cur;

	cur = current_time_ms();
	while (ms > cur - start)
	{
		usleep(1000);
		cur = current_time_ms();
	}
}

long long	current_time_ms(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}
