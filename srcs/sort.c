/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:54:22 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:01:46 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *ptr)
{
	if (ptr->a[0] > ptr->a[1] && ptr->a[1] > ptr->a[2] && ptr->a[0] > ptr->a[2])
	{
		rotate_a(ptr);
		ft_printf("ra\n");
		swap_a(ptr);
	}
	if (ptr->a[0] > ptr->a[1] && ptr->a[0] < ptr->a[2] && ptr->a[1] < ptr->a[2])
		swap_a(ptr);
	if (ptr->a[0] < ptr->a[1] && ptr->a[0] > ptr->a[2] && ptr->a[1] > ptr->a[2])
	{
		reverse_rotate_a(ptr);
		ft_printf("rra\n");
	}
	if (ptr->a[0] < ptr->a[1] && ptr->a[1] > ptr->a[2] && ptr->a[0] < ptr->a[2])
	{
		reverse_rotate_a(ptr);
		ft_printf("rra\n");
		swap_a(ptr);
	}
	if (ptr->a[0] > ptr->a[2] && ptr->a[1] < ptr->a[2] && ptr->a[0] > ptr->a[1])
	{
		rotate_a(ptr);
		ft_printf("ra\n");
	}
}

void	sort_5(t_stack *ptr)
{
	push_b(ptr);
	push_b(ptr);
	sort_3(ptr);
	if (ptr->b[0] > ptr->b[1])
		swap_b(ptr);
	while (ptr->size_b != 0)
	{
		if (ptr->b[0] > check_highest(ptr->a, ptr->size_a))
		{
			while (ptr->a[0] != check_smallest(ptr->a, ptr->size_a))
				check_fastest_a(ptr, ptr->a, ptr->size_a, check_smallest(ptr->a,
						ptr->size_a));
		}
		else
		{
			while (ptr->a[0] != next_smallest(ptr->a, ptr->size_a, ptr->b[0]))
				check_fastest_a(ptr, ptr->a, ptr->size_a, next_smallest(ptr->a,
						ptr->size_a, ptr->b[0]));
		}
		push_a(ptr);
	}
	while (ptr->a[ptr->size_a - 1] != check_highest(ptr->a, ptr->size_a))
		check_fastest_a(ptr, ptr->a, ptr->size_a, check_highest(ptr->a,
				ptr->size_a));
}

void	sort_b(t_stack *ptr, int num)
{
	if ((num > check_highest(ptr->b,
				ptr->size_b) || num < check_smallest(ptr->b,
				ptr->size_b)) && ptr->size_b > 1)
	{
		while (ptr->b[0] != check_highest(ptr->b, ptr->size_b))
			check_fastest_with_counters_b(ptr, ptr->b, ptr->size_b,
				check_highest(ptr->b, ptr->size_b));
		return ;
	}
	else
	{
		while (ptr->b[0] != previous_smallest(ptr->b, ptr->size_b, num))
		{
			if (ptr->size_b > 1)
				check_fastest_with_counters_b(ptr, ptr->b, ptr->size_b,
					previous_smallest(ptr->b, ptr->size_b, num));
			else
				break ;
		}
	}
}

void	sort_a(t_stack *ptr)
{
	int	validator;
	int	num;

	while (ptr->count)
	{
		validator = 1;
		num = get_num_to_push(ptr, ptr->count);
		while (validator)
		{
			sort_b(ptr, num);
			if (ptr->a[0] != num)
				check_fastest_with_counters_a(ptr, ptr->a, ptr->size_a, num);
			else
				validator = 0;
		}
		check_counters(ptr);
		push_b(ptr);
		ptr->count--;
	}
}

void	sort(t_stack *ptr, int chunk_pool)
{
	initialize_counters(ptr);
	while (ptr->size_a != 0)
	{
		if (chunk_pool <= 10)
			ptr->count = 10;
		else if ((ptr->size_a) < chunk_pool)
			ptr->count = ptr->size_a;
		else
			ptr->count = chunk_pool;
		chunk_pool -= 1;
		sort_a(ptr);
	}
	while (ptr->b[0] != check_highest(ptr->b, ptr->size_b))
		check_fastest_b(ptr, ptr->b, ptr->size_b, check_highest(ptr->b,
				ptr->size_b));
	while (ptr->size_b != 0)
		push_a(ptr);
}
