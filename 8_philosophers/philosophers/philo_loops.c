/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:00:05 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/19 05:00:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ekrana yazı yazdıran fonksiyon */
void	print_philos_status(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->lock);
	/* eğer filozof ölmemişse kontrol ediyoruz */
	if (!*philo->is_dead)
	{
		/* informatif tüm satırları yazdırırken kullanılan printf. status
		burada eat, die,
		sleep ve think olabilir. filozof_id'leri ekrana yazdırırken
		1'den başladığı için +1 dedik. */
		printf("[%llu %d %s]\n", (ft_get_time() - philo->start_time), philo->id
				+ 1, status);
		/* eğer kill 1 olarak verilmişse dead_flag'i düzenliyoruz. */
		if (kill)
			*philo->is_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

/* filozofları yemek yedirmek icin bu fonksiyonu kullanıyoruz */
void	eat_time_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	print_philos_status(philo, "has taken a fork ", 0);
	pthread_mutex_lock(philo->right_fork_mutex);
	print_philos_status(philo, "has taken a fork", 0);
	/* her yeme uyuma düşünme vs. eyleminde ft_philo_chec */
	if (ft_philo_check(philo))
		return ;
	print_philos_status(philo, "is eating", 0);
	pthread_mutex_lock(philo->lock);
	philo->last_meal = ft_get_time();
	philo->eaten++;
	pthread_mutex_unlock(philo->lock);
	waiting_philos(philo, philo->eat_time);
}

void	sleep_time_philos(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_check(philo))
		return ;
	print_philos_status(philo, "is sleeping", 0);
	waiting_philos(philo, philo->sleep_time);
}

/* filozofların döngülerini çalıştıran fonksiyon */
void	*loops_for_philos(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	/* filozof sayisi 1 ise ya da koşullara uymuyosa direkt çatal aldırıp öldürüyoruz. */
	if (philo->philo_num == 1 && !ft_philo_check(philo))
	{
		/* eğer sol çatalı kitleyemiyosa null döndürüyoruz. */
		if (pthread_mutex_lock(philo->left_fork_mutex))
			return (NULL);
		print_philos_status(philo, " has taken a fork", 0);
		while (!ft_philo_check(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	/* diğer türlü filo_check hata verip çıkana kadar filozoflara
		1) yediriyoruz
		2) uyutuyoruz
		3) düşündürüyoruz */
	while (1)
	{
		if (ft_philo_check(philo))
			break ;
		eat_time_philos(philo);
		sleep_time_philos(philo);
		if (!ft_philo_check(philo))
			print_philos_status(philo, "is thinking", 0);
	}
	return (NULL);
}
