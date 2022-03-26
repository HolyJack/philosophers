/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 18:24:06 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo(void *ptr_data)
{
	t_data		*data;

	data = (t_data *) ptr_data;
	data->time_last_meal = current_time_ms();
	printf("%lld %d is thinking\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	if (data->l == data->r)
	{
		usleep(data->pinfo->time_to_die * 1000);
		p_die(current_time_ms() - data->pinfo->time_start, data->id);
	}
	while (1)
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
		pthread_mutex_t m_pinfo)
{
	int			i;
	t_data		*data;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (pinfo->number_of_philosophers));
	pinfo->time_start = current_time_ms();
	i = -1;
	while (++i * 2 < pinfo->number_of_philosophers)
	{
		data = data_init(i * 2, pinfo, forks, m_pinfo);
		pthread_create(&threads[i * 2], NULL, philo, (void *) data);
	}
	usleep(1000);
	i = -1;
	while (++i * 2 + 1 < pinfo->number_of_philosophers)
	{
		data = data_init(i * 2 + 1, pinfo, forks, m_pinfo);
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
	pthread_mutex_t	m_pinfo;

	if (argc < 5 || argc > 6)
		return (0);
	pinfo = pinfo_init(argv + 1);
	pthread_mutex_init(&m_pinfo, NULL);
	forks = forks_init(pinfo->number_of_philosophers);
	threads_init(pinfo, forks, m_pinfo);
	free(pinfo);
	free(forks);
	return (0);
}
