/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:57:07 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 22:12:44 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		fork;
	int					id;
	uint64_t			lastmeal;
	int					n_eat;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					n_philo;
	int					te_philo;
	int					ts_philo;
	int					nme_philo;
	int					death;
	int					finish_eat;
	uint64_t			td_philo;
	uint64_t			start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutx;
	pthread_mutex_t		mutx2;
	t_philo				*each_philo;
}						t_data;

int						check_all_arg(int ac, char **av, t_data *data);
uint64_t				get_time(void);
void					my_usleep(uint64_t time, t_data *data);
int						ft_atoi(const char *str);
int						check_death_thread(t_philo *philo);
void					thinking_taken_fork(t_philo *philo);
void					taken_fork_eat(t_philo *philo);
void					releasing_fork_sleep(t_philo *philo);
void					init_philo(t_data *data);
int						return_death(t_data *data, int i, int *j);
void					check_death(t_data *data);
int						check_number_eat(t_data *data, int *count, int i,
							int *j);
#endif
