/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:08:59 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 22:12:39 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number_eat(t_data *data, int *count, int i, int *j)
{
	if (data->nme_philo)
	{
		pthread_mutex_lock(&data->mutx2);
		if (data->each_philo[i].n_eat >= data->nme_philo)
			(*count)++;
		pthread_mutex_unlock(&data->mutx2);
		if (*count == data->n_philo)
		{
			usleep(100);
			pthread_mutex_lock(&data->mutx2);
			data->finish_eat = 1;
			pthread_mutex_unlock(&data->mutx2);
			*j = 0;
			return (1);
		}
	}
	return (0);
}

int	return_death(t_data *data, int i, int *j)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mutx);
	time = (get_time() - data->start) - data->each_philo[i].lastmeal;
	pthread_mutex_unlock(&data->mutx);
	if (time >= data->td_philo)
	{
		pthread_mutex_lock(&data->mutx2);
		data->death = 1;
		pthread_mutex_unlock(&data->mutx2);
		printf("%llu %d died\n", get_time() - data->start, i + 1);
		*j = 0;
		return (1);
	}
	return (0);
}

void	check_death(t_data *data)
{
	int	i;
	int	count;
	int	j;

	j = 1;
	while (j)
	{
		i = 0;
		count = 0;
		while (i < data->n_philo)
		{
			if (check_number_eat(data, &count, i, &j))
				break ;
			if (return_death(data, i, &j))
				break ;
			i++;
		}
	}
}
