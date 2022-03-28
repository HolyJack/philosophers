/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 17:29:18 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo(void *ptr_data)
{
	t_data		*data;

	data = (t_data *) ptr_data;
	data->time_last_meal = current_time_ms();
	p_usleep(data, data->pinfo->time_to_eat * (data->id & 1));
	while (data->times_must_eat)
	{
		grab_forks(data);
		p_eat(data);
		p_sleep(data);
		p_think(data);
	}
	return (0);
}

void	threads_init(
		t_pinfo *pinfo,
		pthread_mutex_t *forks,
		pthread_mutex_t grabing_forks)
{
	int			i;
	t_data		*data;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (pinfo->number_of_philosophers));
	pinfo->time_start = current_time_ms();
	i = -1;
	while (++i < pinfo->number_of_philosophers)
	{
		data = data_init(i, pinfo, forks, grabing_forks);
		pthread_create(&threads[i], NULL, philo, (void *) data);
	}
	i = -1;
	while (++i < pinfo->number_of_philosophers)
		pthread_join(threads[i], NULL);
	free(threads);
}

int	main(int argc, char	**argv)
{
	t_pinfo			*pinfo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	grabing_forks;

	if (argc < 5 || argc > 6)
		return (0);
	pinfo = pinfo_init(argv + 1);
	forks = forks_init(pinfo->number_of_philosophers);
	pthread_mutex_init(&grabing_forks, NULL);
	threads_init(pinfo, forks, grabing_forks);
	free(pinfo);
	free(forks);
	return (0);
}
