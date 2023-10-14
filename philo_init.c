/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:06:52 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 22:07:42 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->each_philo = malloc(data->n_philo * sizeof(t_philo));
	if (!data->each_philo)
		return ;
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return ;
	data->start = get_time();
	pthread_mutex_init(&data->mutx, NULL);
	pthread_mutex_init(&data->mutx2, NULL);
	data->death = 0;
	data->finish_eat = 0;
	while (i < data->n_philo)
	{
		data->each_philo[i].id = i + 1;
		pthread_mutex_init(&data->forks[i], NULL);
		data->each_philo[i].data = data;
		data->each_philo[i].lastmeal = 0;
		data->each_philo[i].n_eat = 0;
		i++;
	}
}
