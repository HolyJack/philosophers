/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/25 13:36:28 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "ft_utils.h"

t_data	*data_init(unsigned int n, t_pinfo *pinfo, pthread_mutex_t *forks)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	data->philo_n = n;
	data->pinfo = pinfo;
	data->forks = forks;
	return (data);
}

t_pinfo	*pinfo_init(char **argv)
{
	t_pinfo	*pinfo;

	pinfo = malloc(sizeof(t_pinfo) * 1);
	pinfo->number_of_philosophers = ft_atoi(argv[0]);
	pinfo->time_to_die = ft_atoi(argv[1]);
	pinfo->time_to_eat = ft_atoi(argv[2]);
	pinfo->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		pinfo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
	else
		pinfo->number_of_times_each_philosopher_must_eat = 0;
	return (pinfo);
}

void	*philo(void *ptr_data)
{
	t_data	*data;

	data = (t_data *) ptr_data;
	printf("Philo number: %d. Time to sleep = %d\n",
		data->philo_n, data->pinfo->time_to_sleep);
	usleep(data->pinfo->time_to_sleep);
	printf("Philo number: %d. Time to eat = %d\n",
		data->philo_n, data->pinfo->time_to_eat);
	usleep(data->pinfo->time_to_eat);
	printf("Philo number: %d. Time to die = %d\n",
		data->philo_n, data->pinfo->time_to_die);
	usleep(data->pinfo->time_to_die);
	printf("Philo number: %d. time to die!\n", data->philo_n);
	free(data);
	return (0);
}

int	main(int argc, char	**argv)
{
	pthread_t		*threads;
	t_data			*data;
	t_pinfo			*pinfo;
	pthread_mutex_t	*forks;
	int				i;

	if (argc < 5 || argc > 6)
		return (0);
	pinfo = pinfo_init(argv + 1);
	forks = malloc(sizeof(pthread_mutex_t) * (pinfo->number_of_philosophers));
	threads = malloc(sizeof(pthread_t) * (pinfo->number_of_philosophers));
	i = -1;
	while (++i < pinfo->number_of_philosophers)
	{
		data = data_init(i, pinfo, forks);
		pthread_create(&threads[i], NULL, philo, (void *) data);
		pthread_mutex_init(&forks[i], NULL);
	}
	i = -1;
	while (++i < pinfo->number_of_philosophers)
		pthread_join(threads[i], NULL);
	free(pinfo);
	free(threads);
	free(forks);
	return (0);
}
