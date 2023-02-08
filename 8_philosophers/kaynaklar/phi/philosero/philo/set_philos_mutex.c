/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:28:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/08 21:39:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// ilklendiriyor filoları vs.
void	init_philos(t_philo *philo, char **av, int ac)
{
	int	*is_dead;
	int	i;

	i = 0;
	is_dead = malloc(sizeof(int));
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
		// şu an için is_dead = 0
		philo[i].is_dead = is_dead;
		i++;
	}
	i = 0;
}

/* ilk parametre özelliklerimizi tutan struct, 2. ve 3. mutexler */
void	init_mutex(t_philo *philo, pthread_mutex_t *fork, pthread_mutex_t *lock)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		/* bu fonksiyon sol ve sağ çatalları belirtmeye yariyor. o filozoflar artık
		sollarındaki ve sağlarındaki çatalları ana structlarına kaydettiler. */
		philo[i].left_fork_mutex = &fork[i];
		philo[i].right_fork_mutex = &fork[(i + 1) % philo->philo_num];
		i++;
	}
	i = 0;
	/* daha sonra filozoflar kitliyorlar çatallarını. */
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
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, &loops_for_philos, &philo[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->philo_num)
		pthread_join(philo[i].thread, NULL);
	while ((*philo).is_dead == 0)
	{
		ft_philo_check(philo);
	}
}
