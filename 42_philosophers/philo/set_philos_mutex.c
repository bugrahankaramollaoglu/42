/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:16:56 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/24 03:25:04 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* filozoflara argümanları atiyoruz */
void init_philos(t_philo *philo, char **av, int ac)
{
	int *is_dead;
	int i;

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
}

void init_mutex(t_philo *philo, pthread_mutex_t *fork, pthread_mutex_t *lock)
{
	int i;

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
		/* bu fonksiyon bir mutexi ilklendiriyor. mutexler,	çoklu threadlerin ortak kullandıgı
		bir veriye erişimi sınırlandırmada kullanılan bir metottur. aynı anda erişilmemesini sağlar
		ilk parametresi	kitlenecek mutex,
		ikincisi ise mutexe extra özellik verirken kullanılır.
		mutexin türünü belirtebiliriz böylece farklı threadler tarafından kitlendiginde farklı
		davranır. bunlar
		* PTHREAD_MUTEX_NORMAL: This is the default type of mutex,
			and it operates in a straightforward manner. If a thread
			tries to lock a mutex that is already locked by another thread,
			it will block until the mutex is unlocked.
		* PTHREAD_MUTEX_ERRORCHECK: This type of mutex provides error checking,
			so that if a thread tries to lock a mutex that it has already locked,
			an error is returned.
		* PTHREAD_MUTEX_RECURSIVE: This type of mutex allows a thread to lock
			the same mutex multiple times without deadlocking.
		bu ikinci parametreyi kullanmak için pthread_mutexattr_t tipinde bir obje oluşturmak,
		daha sonra bu objeyi ilklendirmek, daha sonra da attribute vermek gerekiyor

		********************** KULLANIMI ***********************************

		pthread_mutexattr_t attr;
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

		pthread_mutex_t mutex;
		pthread_mutex_init(&mutex, &attr);

		// Use the mutex...

		pthread_mutex_destroy(&mutex);
		pthread_mutexattr_destroy(&attr);

		**********************

		gibi. şu an her filozofun sol ve sağlarındaki çatalların mutexlerini baslattık,
		henüz kitlemedik.  */
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		/* burada da her bir filozofu kitlemek için kullanacağımız
		filozof mutexi ki bir şey yapmasınlar */
		philo[i].lock = lock;
		i++;
	}
	pthread_mutex_init(philo->lock, NULL);
}

void create_threads(t_philo *philo)
{
	int a;

	a = 0;
	/* filozof sayısı kadar thread yaratiyor çünkü her biri (her bir thread) aynı anda farklı farklı
	işler yapacaklar. her bir thread pthread_t türündedir. */
	while (a < philo->philo_num)
	{
		/* thread yaratmak için pthread_create() kullanılır.
			int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
				void *(*start_routine) (void *), void *arg);
			1) pointer to the pthread_t type. bu threadin kendisidir.
			2) pointer to pthread_attr_t structure. it's optional, just use NULL and the thread
			   will be built with default attributes. if you want to add spesific ones, you may use
			   various functions like pthread_attr_init(), pthread_attr_setstacksize(),
			   or pthread_attr_setschedpolicy(), etc. mesela if you want to create a thread
			   with a specific stack size, you can code:

			   *******************

				pthread_t my_thread;
				pthread_attr_t attr;
				pthread_attr_init(&attr);
				pthread_attr_setstacksize(&attr, 1024*1024); // set stack size to 1 MB
				pthread_create(&my_thread, &attr, my_function, NULL);

			   *******************

			3) yaratılan thread'de çalıştırılacak fonksiyon. void pointer aliyor ve döndürüyor.
			4) o fonksiyona parametre veriyoruz burda da.
		her bir thread yaratıldıktan sonra philo[a] parametresiyle loops_for_philos fonksiyonunu çalıştırır. */
		pthread_create(&philo[a].thread, NULL, &loops_for_philos, &philo[a]);
		/* threadleri yaratırken karışmaması için 100 mikrosaniye bekletiyoruz. */
		usleep(100);
		a++;
	}
	a = 0;
	while (a < philo->philo_num)
		/* 	pthread_join şu işe yarar: bir thread'i başlatmadan diğerinin görevinin bitmesini beklememizi
		sağlar. ilk parametre bitmesi beklenecek thread, ikincisi de thread bitince return
		değerini saklayacak pointer. bir thread pthread_create() fonksiyonu ile yaratıldığında
		o thread main thread altında senkronize (aynı anda) çalışmaya başlar. eğer main thread'i
		child thread işini bitirene kadar bekletmek istiyosak bu fonksiyonu kullaniyoruz. */
		pthread_join(philo[a++].thread, NULL);
	/* bir yandan da sürekli herhangi bir filozof ölüp ölmedi kontrolü yapiliyor. */
	while ((*philo).is_dead == 0)
		ft_philo_check(philo);
}
