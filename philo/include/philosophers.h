/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/31 01:05:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_info
{
	int				number_of_philosophers;
	int				times_must_eat;
	long long		time_start;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	forkslock;
	pthread_mutex_t	printlock;
	t_philo			**philos;
	pthread_t		*threads;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	int				left;
	int				right;
	int				times_must_eat;
	long long		time_last_meal;
	pthread_mutex_t	time_last_meal_lock;
}	t_philo;

void			*philosopher(void *ptr_philo);

t_info			*init_info(char **argv);
t_philo			*init_philo(int n, t_info *info);
pthread_mutex_t	*init_forks(int amount);

void			grab_forks(t_philo *philo);
void			release_forks(t_philo *philo);
void			printstatus(t_philo *philo, char *status);

void			free_info(t_info *info);
void			free_philo(t_philo *philo);
void			free_all_philos(t_philo **philos, int amount);
void			free_forks(pthread_mutex_t *forks, int amount);

long long		current_time_ms(void);
void			philo_usleep(long long ms);

#endif
