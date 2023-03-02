/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/02 17:13:51 by bkaramol         ###   ########.fr       */
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
	/* hem biri işlemini yazarken aynı anda diğeri yazamıyor
	hem de bi tane filo öldüğünde diğerleri işlemlere devam edemiyor
	döngünün devamı için gerekli olan bi sey.  */
	pthread_mutex_t	*lock;

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
	return (0);
}
