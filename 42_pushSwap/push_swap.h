/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:46:56 by bkaramol          #+#    #+#             */
/*   Updated: 2023/04/28 00:25:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_struct
{
	int		*stack_a;
	int		*stack_b;
	int		*sorted;
	int		size_a;
	int		size_b;
	char	*str;
	int		max_bit;
	char	**numbers;
	int		ac_num;
	int		len;
	int		step;
}			t_s;

void		sa(t_s *data);
void		sb(t_s *data);
void		ss(t_s *data);
void		ra(t_s *data);
void		rb(t_s *data);
void		rr(t_s *data);
void		rra(t_s *data);
void		rrb(t_s *data);
void		rrr(t_s *data);
void		pa(t_s *data);
void		pb(t_s *data);
int			*increase_indice(int *arr, int len);
int			*decrease_indice(int *arr, int len);
void		stack_initializer(t_s *data);
void		gather_arguments(t_s *data, char *s);
size_t		ft_strlen(const char *s);
void		num_checker(t_s *data);
void		num_checker2(t_s *data);
void		av_checker(t_s *data);
void		recurrent_nums(t_s *data);
int			word_counter(char *s, char c);
void		fill_stacks(t_s *data);
void		min_max_checker(t_s *data);
void		already_sorted(t_s *data);
void		sort(t_s *data);
void		sort_3(t_s *data);
void		sort_5(t_s *data);
void		bubble_sort(int *arr, unsigned int size);
int			find_index(t_s *data, int nbr);
void		radix(t_s *data);
void		find_maxbit(t_s *data);
void		free_all(t_s *data);
void		error_exit(t_s *data);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *a, char const *b);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str, t_s *data);

#endif
