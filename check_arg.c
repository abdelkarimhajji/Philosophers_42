/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:17:50 by ahajji            #+#    #+#             */
/*   Updated: 2023/10/13 20:03:44 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_valid(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			printf("eroor > 0\n");
			return (1);
		}
		i++;
	}
	data->n_philo = ft_atoi(av[1]);
	data->td_philo = ft_atoi(av[2]);
	data->te_philo = ft_atoi(av[3]);
	data->ts_philo = ft_atoi(av[4]);
	if (ac == 6 && ft_atoi(av[i]) >= 0)
		data->nme_philo = ft_atoi(av[5]);
	else
		data->nme_philo = 0;
	return (0);
}

int	check_all_arg(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				printf("eroor !number\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (check_arg_valid(ac, av, data))
		return (1);
	return (0);
}
