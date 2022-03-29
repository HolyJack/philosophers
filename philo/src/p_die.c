/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_die.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:09:28 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 23:54:29 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_die(long long ms, t_data *data)
{
	pthread_mutex_lock(&data->locks->printlock);
	printf("%lld %d died\n", ms, data->id + 1);
	exit(0);
}
