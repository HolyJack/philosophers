/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/25 13:31:11 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pinfo
{
	int	number_of_philosophers;
	int	number_of_times_each_philosopher_must_eat;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_pinfo;

typedef struct s_data
{
	unsigned int	philo_n;
	t_pinfo			*pinfo;
	pthread_mutex_t	*forks;
}	t_data;

#endif
