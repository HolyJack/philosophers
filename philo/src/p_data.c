/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:17:10 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 17:49:20 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*data_init(
		unsigned int n, t_pinfo *pinfo,
		pthread_mutex_t *forks,
		pthread_mutex_t grabing_forks)
{
	t_data			*data;

	data = malloc(sizeof(t_data) * 1);
	data->id = n;
	data->pinfo = pinfo;
	data->forks = forks;
	data->grabing_forks = grabing_forks;
	data->times_must_eat = data->pinfo->times_must_eat;
	data->r = n;
	data->l = n + 1;
	if (data->l == data->pinfo->number_of_philosophers)
		data->l = 0;
	return (data);
}
