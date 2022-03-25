/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:47:16 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo(void *ptr_data)
{
	t_data		*data;

	data = (t_data *) ptr_data;
	data->time_last_meal = current_time_ms();
	p_think(data);
	while (data->pinfo->number_of_times_each_philosopher_must_eat)
	{
		checkdead(data);
		p_eat(data);
		p_sleep(data);
		p_think(data);
	}
	free(data);
	return (0);
}

void	threads_init(
		t_pinfo *pinfo,
		pthread_mutex_t *forks,
		pthread_mutex_t meal)
{
	int			i;
	t_data		*data;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (pinfo->number_of_philosophers));
	i = -1;
	while (++i * 2 < pinfo->number_of_philosophers)
	{
		data = data_init(i * 2, pinfo, forks, meal);
		pthread_create(&threads[i * 2], NULL, philo, (void *) data);
	}
	usleep(50);
	i = -1;
	while (++i * 2 + 1 < pinfo->number_of_philosophers)
	{
		data = data_init(i * 2 + 1, pinfo, forks, meal);
		pthread_create(&threads[i * 2 + 1], NULL, philo, (void *) data);
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
	pthread_mutex_t	meal;

	if (argc < 5 || argc > 6)
		return (0);
	pinfo = pinfo_init(argv + 1);
	pthread_mutex_init(&meal, NULL);
	forks = forks_init(pinfo->number_of_philosophers);
	threads_init(pinfo, forks, meal);
	free(pinfo);
	free(forks);
	return (0);
}
