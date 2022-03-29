/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:17:10 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:14:31 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*p_init_data(
		int n, t_pinfo *pinfo, pthread_mutex_t *forks, t_locks *locks)
{
	t_data			*data;

	data = malloc(sizeof(t_data) * 1);
	data->id = n;
	data->pinfo = pinfo;
	data->forks = forks;
	data->times_must_eat = data->pinfo->times_must_eat;
	data->locks = locks;
	data->right = n;
	data->left = n + 1;
	if (data->left == data->pinfo->number_of_philosophers)
		data->left = 0;
	return (data);
}
