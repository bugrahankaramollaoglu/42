/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:06:38 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/19 02:37:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_check(t_philo *philo)
{
	if (philo->eaten == philo->goal)
		return (1);
	pthread_mutex_lock(philo->lock);
	if (*philo->is_dead)
	{
		pthread_mutex_unlock(philo->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->lock);
	if (ft_get_time() - philo->last_meal > philo->die_time)
	{
		print_philos_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

int	waiting_philos(t_philo *philo, t_time wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < wait_time)
	{
		if (ft_philo_check(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
