/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 17:05:21 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_pinfo
{
	int			meals_finished;
	int			number_of_philosophers;
	int			times_must_eat;
	long long	time_start;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
}	t_pinfo;

typedef struct s_data
{
	int				id;
	int				l;
	int				r;
	int				times_must_eat;
	long long		time_last_meal;
	t_pinfo			*pinfo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_pinfo;
}	t_data;

#endif
