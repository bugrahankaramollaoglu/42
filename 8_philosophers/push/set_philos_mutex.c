/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:07:21 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/09 21:13:41 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_initialize(t_philo *philo, char **av, int ac)
{
	int	*is_dead;
	int	i;

	i = 0;
	is_dead = malloc(sizeof(int));
	if (!is_dead)
		return ;
	*is_dead = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i;
		philo[i].die_time = ft_atoi(av[2]);
		philo[i].eat_time = ft_atoi(av[3]);
		philo[i].sleep_time = ft_atoi(av[4]);
		if (ac == 6)
			philo[i].goal = ft_atoi(av[5]);
		else
			philo[i].goal = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].eaten = 0;
		philo[i].philo_num = ft_atoi(av[1]);
		philo[i].is_dead = is_dead;
		i++;
	}
}

void	init_mutex(t_philo *philo, pthread_mutex_t *fork, pthread_mutex_t *lock)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		philo[i].left_fork_mutex = &fork[i];
		philo[i].right_fork_mutex = &fork[(i + 1) % philo->philo_num];
		i++;
	}
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].lock = lock;
		i++;
	}
	pthread_mutex_init(philo->lock, NULL);
}

void	create_threads(t_philo *philo)
{
	int	a;

	a = 0;
	while (a < philo->philo_num)
	{
		pthread_create(&philo[a].thread, NULL, &philos_looping, &philo[a]);
		usleep(100);
		a++;
	}
	a = 0;
	while (a < philo->philo_num)
		pthread_join(philo[a++].thread, NULL);
	while ((*philo).is_dead == 0)
		philosopher_check(philo);
}
