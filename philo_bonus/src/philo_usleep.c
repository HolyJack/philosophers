/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_usleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:34:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 21:46:06 by ejafer           ###   ########.fr       */
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
