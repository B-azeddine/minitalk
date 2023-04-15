/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:20:46 by ablidi            #+#    #+#             */
/*   Updated: 2023/03/27 21:21:30 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	converty(char c, int pid)
{
	int	bits[8];
	int	i;

	i = 0;
	while (i < 8)
		bits[i++] = 0;
	i = 0;
	while (i < 8)
	{
		bits[i] = c % 2;
		c = c / 2;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (bits[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		converty(str[cur], pid);
		cur++;
	}
	converty(0, pid);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr("invalid pid ! \n");
		return (EXIT_FAILURE);
	}
	send_str(argv[2], pid);
	return (0);
}
