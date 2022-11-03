/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:53:42 by jlima             #+#    #+#             */
/*   Updated: 2022/06/13 12:31:16 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	rotate_a;
	int	rotate_b;
	int	reverse_rotate_a;
	int	reverse_rotate_b;
	int	count;
}		t_stack;

int		main(int argc, char *argv[]);
int		check_argvs(char *argv[], int argc);
void	init_stacks(t_stack *ptr, int argc, char *argv[], char *split[]);
void	init_for_split(t_stack *ptr, char *split[]);
void	initialize_counters(t_stack *ptr);
void	sort_3(t_stack *ptr);
void	sort_5(t_stack *ptr);
void	sort(t_stack *ptr, int chunk_pool);
void	pick_sort_option(t_stack *ptr);
int		check_num_position_stack(int *arr, int size, int num);
int		check_smallest(int *arr, int size);
void	*array_of_smallest(int *arr, int size, int count);
int		previous_smallest(int *arr, int size, int smallest);
int		next_smallest(int *arr, int size, int smallest);
int		check_highest(int *arr, int size);
void	check_fastest_a(t_stack *ptr, int *arr, int size, int num);
void	check_fastest_b(t_stack *ptr, int *arr, int size, int num);
void	check_fastest_with_counters_a(t_stack *ptr, int *arr, int size,
			int num);
void	check_fastest_with_counters_b(t_stack *ptr, int *arr, int size,
			int num);
void	check_counters(t_stack *ptr);
void	check_remaining_counters(t_stack *ptr);
int		get_num_to_push(t_stack *ptr, int count);
void	*pick_better_num_to_push(int (*array)[2], int *arr, int size,
			int count);
int		get_number_for_smaller_route(int (*array)[2], int count);

void	swap_a(t_stack *ptr);
void	swap_b(t_stack *ptr);
void	push_a(t_stack *ptr);
void	push_b(t_stack *ptr);
void	rotate_a(t_stack *ptr);
void	rotate_b(t_stack *ptr);
void	reverse_rotate_a(t_stack *ptr);
void	reverse_rotate_b(t_stack *ptr);

#endif
