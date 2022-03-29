/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:46:12 by ejafer           ###   ########.fr       */
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
	int			times_must_eat;
	long long	time_start;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
}	t_pinfo;

typedef struct s_locks
{
	pthread_mutex_t	forkslock;
	pthread_mutex_t	printlock;
}	t_locks;

typedef struct s_data
{
	int				id;
	int				left;
	int				right;
	int				times_must_eat;
	long long		time_last_meal;
	t_pinfo			*pinfo;
	t_locks			*locks;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time_last_meal_lock;
}	t_data;

t_data			*p_init_data(int n, t_pinfo *pinfo,
					pthread_mutex_t *forks, t_locks *locks);
t_pinfo			*p_init_info(char **argv);
t_locks			*p_init_locks(void);
pthread_mutex_t	*p_init_forks(int amount);
int				p_isvalid_inputs(int argc, char **argv);

void			p_free_forks(pthread_mutex_t *forks, int amount);

void			p_sleep(t_data *data);
void			p_eat(t_data *data);
void			p_think(t_data *data);
void			p_die(long long ms, t_data *data);
void			p_grab_forks(t_data *data);
void			p_release_forks(t_data *data);

long long		p_current_time_ms(void);
long long		p_passed_time_ms(long long start);
void			*p_checkdead(void *ptr_data);
void			p_usleep(long long mcs);
void			p_printstatus(t_data *data,
					long long timestamp,
					int id, char *status);

#endif
