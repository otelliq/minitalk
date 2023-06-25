/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:15:54 by otelliq           #+#    #+#             */
/*   Updated: 2023/04/11 03:30:37 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char			bit;
	static unsigned int	c;
	static int			get_pid;

	(void)context;
	if (info->si_pid != get_pid)
	{
		bit = 0;
		c = 0;
		get_pid = info->si_pid ;
	}
	if (signal == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0;
		get_pid = info->si_pid;
	}
}

void	config(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

int	main(void)
{
	ft_putstr("SERVER PID :");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		config();
}
