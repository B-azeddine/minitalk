/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:22:40 by ablidi            #+#    #+#             */
/*   Updated: 2023/03/27 02:44:08 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	skip(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\n' || str[i] == '\r'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	mark;
	int	result;
	int	i;

	i = 0;
	result = 0;
	mark = 1;
	i = skip(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mark = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	result = result * mark;
	return (result);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int a)
{
	char	cmt;

	if (a >= 0 && a <= 9)
	{
		cmt = a + '0';
		ft_putchar(cmt);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
}
