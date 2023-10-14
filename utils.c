/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:49:44 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 20:04:50 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	st;
	int	result;

	st = 1;
	i = 0;
	result = 0;
	while ((str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			st *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * st);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_usleep(uint64_t time, t_data *data)
{
	uint64_t	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= time)
			break ;
		pthread_mutex_lock(&data->mutx2);
		if (data->death == 1)
		{
			pthread_mutex_unlock(&data->mutx2);
			break ;
		}
		pthread_mutex_unlock(&data->mutx2);
		usleep(200);
	}
}
