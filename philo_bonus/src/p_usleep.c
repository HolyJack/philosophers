/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_usleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:34:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 16:41:07 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_usleep(long long ms)
{
	const long long	start = p_current_time_ms();
	long long		cur;

	cur = p_current_time_ms();
	while (ms > cur - start)
	{
		usleep(1000);
		cur = p_current_time_ms();
	}
}
