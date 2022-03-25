/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:42 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:35:28 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	current_time_mcs(void)
{
	struct timeval	time;
	long long		mcs;

	gettimeofday(&time, NULL);
	mcs = time.tv_sec % 1000000 * 1000000 + time.tv_usec;
	return (mcs);
}

long long	current_time_ms(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}
