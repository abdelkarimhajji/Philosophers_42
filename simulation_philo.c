/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:59:58 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 22:24:02 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death_thread(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death == 1 || philo->data->finish_eat == 1)
	{
		pthread_mutex_unlock(&philo->data->mutx2);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutx2);
	return (0);
}

void	thinking_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death != 1)
		printf("%lld %d is thinking\n", get_time() - philo->data->start,
			philo->id);
	pthread_mutex_unlock(&philo->data->mutx2);
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death != 1)
		printf("%lld %d has taken a fork\n", get_time() - philo->data->start,
			philo->id);
	pthread_mutex_unlock(&philo->data->mutx2);
}

void	taken_fork_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->n_philo]);
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death != 1)
		printf("%lld %d has taken a fork\n", get_time() - philo->data->start,
			philo->id);
	pthread_mutex_unlock(&philo->data->mutx2);
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death != 1)
		printf("%lld %d is eating\n", get_time() - philo->data->start,
			philo->id);
	pthread_mutex_unlock(&philo->data->mutx2);
	pthread_mutex_lock(&philo->data->mutx);
	philo->lastmeal = (get_time() - philo->data->start);
	pthread_mutex_unlock(&philo->data->mutx);
	pthread_mutex_lock(&philo->data->mutx2);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->data->mutx2);
	my_usleep(philo->data->te_philo, philo->data);
}

void	releasing_fork_sleep(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->n_philo]);
	pthread_mutex_lock(&philo->data->mutx2);
	if (philo->data->death != 1)
		printf("%lld %d is sleeping\n", get_time() - philo->data->start,
			philo->id);
	pthread_mutex_unlock(&philo->data->mutx2);
	my_usleep(philo->data->ts_philo, philo->data);
}
