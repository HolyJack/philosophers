/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printstatus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:50:20 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 23:26:49 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_printstatus(t_data *data, long long timestamp, int id, char *status)
{
	pthread_mutex_lock(&data->locks->printlock);
	printf("%lld %d %s\n", timestamp, id, status);
	pthread_mutex_unlock(&data->locks->printlock);
}
