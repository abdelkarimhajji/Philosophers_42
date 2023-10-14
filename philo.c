/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:57:18 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 22:14:32 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_death_thread(philo))
			break ;
		thinking_taken_fork(philo);
		if (philo->data->n_philo == 1)
		{
			my_usleep(philo->data->td_philo, philo->data);
			break ;
		}
		taken_fork_eat(philo);
		releasing_fork_sleep(philo);
	}
	return (NULL);
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&data->each_philo[i].thread, NULL, print,
			&data->each_philo[i]);
		usleep(50);
		i += 2;
	}
	i = 1;
	while (i < data->n_philo)
	{
		pthread_create(&data->each_philo[i].thread, NULL, print,
			&data->each_philo[i]);
		usleep(50);
		i += 2;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->each_philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("number of arg not valid"), 0);
	if (check_all_arg(ac, av, &data))
		return (1);
	init_philo(&data);
	create_thread(&data);
	check_death(&data);
	join_threads(&data);
	free(data.each_philo);
	free(data.forks);
	return (0);
}
