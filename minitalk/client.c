/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:43:56 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/11 05:14:50 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_sender(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

int	pid_check(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (!ft_isdigit(path[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		exit(EXIT_FAILURE);
	}
	if (!pid_check(av[1]))
		return (EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(EXIT_FAILURE);
	if (ac == 3)
	{
		while (av[2][i] != 0)
			signal_sender(pid, av[2][i++]);
	}	
	return (0);
}
