/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:58:32 by ablidi            #+#    #+#             */
/*   Updated: 2023/03/29 18:32:41 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bits[8];

int	pow2(int n)
{
	int	res;

	res = 1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		res *= 2;
		n--;
	}
	return (res);
}

int	convert_bin_to_dec(void)
{
	int	j;
	int	i;
	int	res;

	i = 0;
	res = 0;
	j = 7;
	while (j >= 0)
	{
		res = res + g_bits[j] * pow2(i);
		j--;
		i++;
	}
	return (res);
}

void	sig_handler(int sig, siginfo_t *sig_inf, void *smia)
{
	static int	i = 7;
	static int	old_pid = 0 ;

	(void)smia;
	if (sig_inf->si_pid != old_pid)
	{
		old_pid = sig_inf->si_pid;
		i = 7;
	}
	if (sig == SIGUSR1)
		g_bits[i] = 0;
	if (sig == SIGUSR2)
		g_bits[i] = 1;
	if (i == 0)
	{
		ft_putchar(convert_bin_to_dec());
		i = 7;
	}
	else
		i--;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 1)
		return (EXIT_FAILURE);
	(void)av;
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = 0;
	pid = getpid();
	ft_putstr("your pid is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
