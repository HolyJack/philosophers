/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_locks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:59:55 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:46:29 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_locks	*p_init_locks(void)
{
	t_locks	*locks;

	locks = malloc(sizeof(t_locks) * 1);
	pthread_mutex_init(&locks->forkslock, NULL);
	pthread_mutex_init(&locks->printlock, NULL);
	return (locks);
}
