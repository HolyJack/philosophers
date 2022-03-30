/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 21:42:29 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <errno.h>

# define FORKS "forks"
# define LOCK_FORKS "forkslock"
# define LOCK_PRINT "lockprint"
# define ALL_FINISHED "allfinished"

typedef struct s_info
{
	int			id;
	int			number_of_philosophers;
	int			times_must_eat;
	long long	time_start;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	time_last_meal;
	sem_t		*forks;
	sem_t		*lock_forks;
	sem_t		*lock_print;
	sem_t		*all_finished;
	sem_t		lock_eat;
	pthread_t	deathstatus;
}	t_info;

t_info		*init_info(char **argv);
void		free_info(t_info *info);
void		philosopher(t_info *info);
int			isvalid_inputs(int argc, char **argv);
long long	current_time_ms(void);
void		philo_usleep(long long ms);
void		print_status(t_info *info, char *status);

#endif
