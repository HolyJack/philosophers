/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:17:10 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 15:57:05 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*data_init(
		unsigned int n, t_pinfo *pinfo,
		pthread_mutex_t *forks,
		pthread_mutex_t m_pinfo)
{
	t_data			*data;

	data = malloc(sizeof(t_data) * 1);
	data->id = n;
	data->pinfo = pinfo;
	data->forks = forks;
	data->m_pinfo = m_pinfo;
	data->times_must_eat = data->pinfo->times_each_philosopher_must_eat;
	data->r = n;
	data->l = n + 1;
	if (data->l == data->pinfo->number_of_philosophers)
	{
		data->r = 0;
		data->l = n;
	}
	return (data);
}
