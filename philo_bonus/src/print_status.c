/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:15:40 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 00:19:16 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_info *info, char *status)
{
	sem_wait(info->lock_print);
	printf("%lld %d %s\n",
		current_time_ms() - info->time_start, info->id, status);
	sem_post(info->lock_print);
}
