/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:59:22 by ejafer           ###   ########.fr       */
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
	int			number_of_philosophers;
	int			number_of_times_each_philosopher_must_eat;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	//long long	time_delay;
}	t_pinfo;

typedef struct s_data
{
	int				id;
	int				l;
	int				r;
	long long		time_last_meal;
	t_pinfo			*pinfo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
}	t_data;

t_data			*data_init(
					unsigned int n, t_pinfo *pinfo,
					pthread_mutex_t *forks,
					pthread_mutex_t meal);
t_pinfo			*pinfo_init(char **argv);
pthread_mutex_t	*forks_init(int amount);

void			p_sleep(t_data *data);
void			p_eat(t_data *data);
void			p_think(t_data *data);
void			grab_forks(t_data *data);
void			release_forks(t_data *data);

long long		current_time_ms(void);
long long		current_time_mcs(void);
long long		passed_time_ms(long long start);
void			checkdead(t_data *data);

#endif
