/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:39:29 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 21:21:44 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "ft_utils.h"

void	threads_init(t_info *info)
{
	int			i;
	t_philo		*philo;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (info->number_of_philosophers));
	info->threads = threads;
	info->time_start = current_time_ms();
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		philo = init_philo(i, info);
		philo->info->philos[i] = philo;
		pthread_create(&threads[i], NULL, philosopher, (void *) philo);
	}
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(threads[i], NULL);
}

int	main(int argc, char	**argv)
{
	t_info		*info;

	if (!isvalid_inputs(argc - 1, argv + 1))
		return (0);
	info = init_info(argv + 1);
	threads_init(info);
	free_info(info);
	return (0);
}
