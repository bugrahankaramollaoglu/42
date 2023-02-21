/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:06:52 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/21 20:26:14 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_status(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->lock);
	if (!*philo->is_dead)
	{
		printf("[%llu %d %s]\n", (ft_get_time() - philo->start_time), philo->id
				+ 1, status);
		if (kill)
			*philo->is_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

void	philos_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	display_status(philo, "has taken a fork ", 0);
	pthread_mutex_lock(philo->right_fork_mutex);
	display_status(philo, "has taken a fork", 0);
	if (philosopher_check(philo))
		return ;
	display_status(philo, "is eating", 0);
	pthread_mutex_lock(philo->lock);
	philo->last_meal = ft_get_time();
	philo->eaten++;
	pthread_mutex_unlock(philo->lock);
	philos_waiting(philo, philo->eat_time);
}

void	philos_sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (philosopher_check(philo))
		return ;
	display_status(philo, "is sleeping", 0);
	philos_waiting(philo, philo->sleep_time);
}

void	*philos_looping(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	if (philo->philo_num == 1 && !philosopher_check(philo))
	{
		if (pthread_mutex_lock(philo->left_fork_mutex))
			return (NULL);
		display_status(philo, " has taken a fork", 0);
		while (!philosopher_check(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	while (1)
	{
		if (philosopher_check(philo))
			break ;
		philos_eating(philo);
		philos_sleeping(philo);
		if (!philosopher_check(philo))
			display_status(philo, "is thinking", 0);
	}
	return (NULL);
}
