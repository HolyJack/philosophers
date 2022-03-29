/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:20:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo(void *ptr_data)
{
	t_data			*data;
	pthread_t		deatstatus;

	data = (t_data *) ptr_data;
	data->time_last_meal = p_current_time_ms();
	pthread_mutex_init(&data->time_last_meal_lock, NULL);
	pthread_create(&deatstatus, NULL, p_checkdead, (void *) data);
	p_usleep(data->pinfo->time_to_eat * (data->id & 1) - 10);
	while (data->times_must_eat)
	{
		p_eat(data);
		p_sleep(data);
		p_think(data);
	}
	pthread_join(deatstatus, NULL);
	return (0);
}

void	threads_init(
		t_pinfo *pinfo,
		pthread_mutex_t *forks,
		t_locks *locks)
{
	int			i;
	t_data		*data;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (pinfo->number_of_philosophers));
	pinfo->time_start = p_current_time_ms();
	i = -1;
	while (++i < pinfo->number_of_philosophers)
	{
		data = p_init_data(i, pinfo, forks, locks);
		pthread_create(&threads[i], NULL, philo, (void *) data);
	}
	i = -1;
	while (++i < pinfo->number_of_philosophers)
		pthread_join(threads[i], NULL);
}

int	main(int argc, char	**argv)
{
	t_pinfo			*pinfo;
	t_locks			*locks;
	pthread_mutex_t	*forks;

	if (!p_isvalid_inputs(argc - 1, argv + 1))
		return (0);
	pinfo = p_init_info(argv + 1);
	locks = p_init_locks();
	forks = p_init_forks(pinfo->number_of_philosophers);
	threads_init(pinfo, forks, locks);
	return (0);
}
