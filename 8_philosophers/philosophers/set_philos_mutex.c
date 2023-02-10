/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:03:01 by nliman            #+#    #+#             */
/*   Updated: 2023/02/10 18:07:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		philo[i].is_dead = is_dead;
		i++;
	}
	i = 0;
}

/* ilk parametre filozofların özelliklerini tutan struct, 2. ve 3. mutexler */
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
	/* bu fonksiyon bir mutexi ilklendiriyor. mutex,
		çoklu threadlerin kullandıgı
	ortak bir veriye erişimi sınırlandırmada kullanılan bir metottur. ilk parametresi
	kitlenecek mutex,
		ikincisi ise mutexe extra özellik verirken kullanılır. mutexin türünü
	belirtebiliriz böylece farklı threadler tarafından kitlendiginde farklı davranır. bunlar
		* PTHREAD_MUTEX_NORMAL: This is the default type of mutex,
			and it operates in a straightforward manner. If a thread
			tries to lock a mutex that is already locked by another thread,
			it will block until the mutex is unlocked.
		* PTHREAD_MUTEX_ERRORCHECK: This type of mutex provides error checking,
			so that if a thread tries to lock a mutex that it has already locked,
			an error is returned.
		* PTHREAD_MUTEX_RECURSIVE: This type of mutex allows a thread to lock
			the same mutex multiple times without deadlocking.
		*/
	pthread_mutex_init(philo->lock, NULL);
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	/* filozof sayısı kadar thread yaratiyor çünkü her biri (her bir thread) aynı anda farklı farklı
	işler yapacaklar */
	while (i < philo->philo_num)
	{
		/* thread yaratmak için pthread_create() kullanılır.
		int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
				void *(*start_routine) (void *), void *arg);
			1) pointer to the pthread_t type. bu threadin tipidir.
			2) pointer to pthread_attr_t structure. it's optional, just use NULL
			3) pointer to function that will be run by the new thread. it takes void pointer and returns void.
			4) an argument to be passed to the start_routine function. This argument can be any pointer value,
			including NULL.
		her bir thread yaratıldıktan sonra philo[i] parametresiyle loops_for_philos fonksiyonunu çalıştırır. */
		pthread_create(&philo[i].thread, NULL, &loops_for_philos, &philo[i]);
		i++;
		/* threadleri yaratırken karışmaması için 100 mikrosaniye bekletiyoruz. */
		usleep(100);
	}
	i = 0;
	/* daha sonra thread (filozof) sayısı kadar pthread_join uyguluyoruz her bir threade. */
	while (i < philo->philo_num)
		/* 	pthread_join şu işe yarar: bir thread'i başlatmadan diğerinin görevinin bitmesini beklememizi
		sağlar. ilk parametresi beklenecek thread,
		ikincisi ise dönüş değerini saklayacak pointerdır (optional). */
		pthread_join(philo[i++].thread, NULL);
	/* bir yandan da sürekli herhangi bir filozofun ölüp ölmedi kontrolü yapiliyor. */
	while ((*philo).is_dead == 0)
		ft_philo_check(philo);
}
