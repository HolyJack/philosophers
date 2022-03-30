/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:03:08 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 22:31:54 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(char *status)
{
	printf("Error: %s\n", status);
	exit(0);
}

pid_t	init_philos(t_info *info, pid_t *child_pids)
{
	int		i;
	pid_t	pid;

	i = -1;
	pid = 1;
	while (++i < info->number_of_philosophers)
	{
		pid = fork();
		if (pid < 0)
		{
			free(child_pids);
			free_info(info);
			error("fork error");
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
	int	status;

	if (pid == 0)
	{
		philosopher(info);
		exit(0);
	}
	else if (pid > 0)
	{	
		while (1)
		{
			pid = waitpid(-1, &status, 0);
			if (errno == ECHILD)
				break ;
			i = -1;
			while (++i < info->number_of_philosophers)
				kill(child_pids[i], SIGTERM);
			status = 0;
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
