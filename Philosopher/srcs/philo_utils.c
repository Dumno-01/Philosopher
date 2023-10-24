/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:13:53 by ffreze            #+#    #+#             */
/*   Updated: 2023/10/16 08:13:53 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atoi(const char *str)
{
	int						i;
	unsigned long int		nbr;
	int						sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
		if ((char)str[i++] == '-')
			sign ++;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
		nbr = nbr * 10 + ((char)str[i++] - '0');
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

int	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (error(ERR_INPUT_1, NULL));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	ft_usleep(useconds_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}