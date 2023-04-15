/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:32:23 by ablidi            #+#    #+#             */
/*   Updated: 2023/03/28 18:26:15 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		skip(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int a);

#endif