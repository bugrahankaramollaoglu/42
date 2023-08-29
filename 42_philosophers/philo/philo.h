/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:01 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/19 01:03:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef unsigned long long t_time;

typedef struct s_philo
{
	int id;
	int goal;
	int philo_num;
	int eaten;
	int *is_dead;
	t_time die_time;
	t_time eat_time;
	t_time sleep_time;
	t_time start_time;
	t_time last_meal;
	pthread_t thread;
	pthread_mutex_t *lock;
	pthread_mutex_t *left_fork_mutex;
	pthread_mutex_t *right_fork_mutex;
} t_philo;

void init_philos(t_philo *philo, char **av, int ac);
void init_mutex(t_philo *philo, pthread_mutex_t *fork,
				pthread_mutex_t *lock);
void create_threads(t_philo *philo);
void *loops_for_philos(void *argument);
void print_philos_status(t_philo *philo, char *status, int kill);
void eat_time_philos(t_philo *philo);
void sleep_time_philos(t_philo *philo);
int waiting_philos(t_philo *philo, unsigned long long wait_time);
int ft_philo_check(t_philo *philo);
int arg_checks(int ac, char **av);
long ft_atoi(const char *str);
void ft_free(t_philo *philo, pthread_mutex_t *fork, pthread_mutex_t *lock);
t_time ft_get_time(void);
int is_digit(char *str);
#endif
