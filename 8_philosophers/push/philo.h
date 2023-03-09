/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:01 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/09 00:28:27 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int						id;
	int						goal;
	int						philo_num;
	int						eaten;
	int						*is_dead;
	t_time					die_time;
	t_time					eat_time;
	t_time					sleep_time;
	t_time					start_time;
	t_time					last_meal;
	pthread_t				thread;
	pthread_mutex_t			*lock;
	pthread_mutex_t			*left_fork_mutex;
	pthread_mutex_t			*right_fork_mutex;
}							t_philo;

void						philo_initialize(t_philo *philo, char **av, int ac);
void						init_mutex(t_philo *philo, pthread_mutex_t *fork,
								pthread_mutex_t *lock);
void						create_threads(t_philo *philo);
void						*philos_looping(void *argument);
void						display_status(t_philo *philo, char *status,
								int kill);
void						philos_eating(t_philo *philo);
void						philos_sleeping(t_philo *philo);
int							philos_waiting(t_philo *philo,
								unsigned long long wait_time);
int							philosopher_check(t_philo *philo);
int							arg_checks(int ac, char **av);
long						ft_atoi(const char *str);
void						ft_free(t_philo *philo, pthread_mutex_t *fork,
								pthread_mutex_t *lock);
t_time						ft_get_time(void);
int							is_digit(char *str);

#endif
