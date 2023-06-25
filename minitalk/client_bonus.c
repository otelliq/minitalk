/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:48:14 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/11 05:16:37 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

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

void	ft_bonus(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message received successfully!", 29);
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
	{
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ft_bonus);
	if (ac == 3)
	{
		while (av[2][i] != 0)
			signal_sender(pid, av[2][i++]);
		signal_sender(pid, '\0');
	}	
	return (0);
}
