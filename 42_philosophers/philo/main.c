/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/11 04:58:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
		{
			printf("you entered invalid argument!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*lock;

	/* hem biri işlemini yazarken aynı anda diğeri yazamıyor
	hem de bi tane filo öldüğünde diğerleri işlemlere devam edemiyor
	döngünün devamı için gerekli olan bi sey.  */
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			// thread'lere yer ayırıyoruz
			philo = malloc(sizeof(*philo) * ft_atoi(av[1]));
			fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
			lock = malloc(sizeof(pthread_mutex_t));
			if (!philo || !fork || !lock)
				return (1);
			// ilklendirme işlemlerini yapiyoruz
			init_philos(philo, av, ac);
			// kitleme işlemi yapiyor
			init_mutex(philo, fork, lock);
			// thread yaratiyor
			create_threads(philo);
			ft_free(philo, fork, lock);
		}
	}
	// system("leaks philo");
	return (0);
}

/* data race örnegi --> gcc main.c -fsanitize=thread

#include <pthread.h>
#include <stdio.h>

int	count = 0;

void* increment(void* arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        count++;
    }
    return (NULL);
}

int	main(void) {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final count value: %d\n", count);
    return (0);
}

yukarıdaki kodda ortak bir count isminde değişkenimiz var. global tanımladıgımız
bu değişkeni iki thread de arttırmaya çalışıyor. pthread_create() fonksiyonlarından
birini silersek bu degisken istendigi gibi 100000 oluyor fakat aynı anda ikisi de
yaparsa (paralel) tamamlanamadan data race oluyor ve her calıstıgında random bir yerde
arttırma islemi tıkanıyor. mutex ya da semaphore gibi senkronizasyon islemi kullanmadıgımız
icin bu sorun meydana geliyor. the final value of count is not deterministic,
and can vary between runs of the program. This is because both threads are racing to increment count,
and it's possible for one thread to read the value of count, increment it,
and write the new value back to count before the other thread has a chance to read
the updated value. This can result in lost updates or overwrites,
leading to an incorrect final value for count.

In the code above,
	we use pthread_join() twice to wait for both thread1 and thread2
to complete before printing the final value of count. This ensures that we get
the correct final value of count,
	and that the program does not terminate prematurely. */

