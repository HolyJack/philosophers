/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:37:11 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 21:46:09 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_info(t_info *info)
{
	sem_unlink(FORKS);
	sem_unlink(LOCK_PRINT);
	sem_unlink(LOCK_FORKS);
	sem_unlink(ALL_FINISHED);
	sem_close(info->forks);
	sem_close(info->lock_print);
	sem_close(info->lock_forks);
	sem_close(info->all_finished);
	sem_close(&info->lock_eat);
	free(info);
}
