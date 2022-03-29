/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:03:08 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 01:02:13 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pid_t	init_philos(t_info *info, pid_t *child_pids)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < info->number_of_philosophers)
	{
		pid = fork();
		if (pid < 0)
		{
			printf("Error: %s\n", "fork error");
			free(child_pids);
			free_info(info);
			exit(0);
		}
		else if (pid == 0)
		{
			info->id = i + 1;
			free(child_pids);
			child_pids = NULL;
			break ;
		}
		else
			child_pids[i] = pid;
	}
	return (pid);
}

void	wait_for_philos(pid_t pid, t_info *info, pid_t *child_pids)
{
	int	i;

	if (pid == 0)
	{
		philosopher(info);
		exit(0);
	}
	else if (pid > 0)
	{
		pid = waitpid(-1, NULL, 0);
		i = -1;
		while (++i < info->number_of_philosophers)
			kill(child_pids[i], SIGTERM);
		while (1)
		{
			pid = waitpid(-1, NULL, 0);
			if (errno == ECHILD)
				break ;
		}
		free(child_pids);
		free_info(info);
	}
}

int	main(int argc, char	**argv)
{
	pid_t	*child_pids;
	pid_t	pid;
	t_info	*info;

	if (!isvalid_inputs(argc - 1, argv + 1))
		return (0);
	info = init_info(argv + 1);
	child_pids = malloc(sizeof(pid_t) * info->number_of_philosophers);
	pid = init_philos(info, child_pids);
	wait_for_philos(pid, info, child_pids);
	return (0);
}
