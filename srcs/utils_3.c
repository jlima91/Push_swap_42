/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:00:47 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:02:04 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num_position_stack(int *arr, int size, int num)
{
	int	mid;
	int	i;

	i = 0;
	while (arr[i] != num)
		i++;
	mid = size / 2;
	if (i <= mid)
		return (1);
	else
		return (0);
}

void	check_fastest_a(t_stack *ptr, int *arr, int size, int num)
{
	if (check_num_position_stack(arr, size, num))
	{
		rotate_a(ptr);
		ft_printf("ra\n");
	}
	else
	{
		reverse_rotate_a(ptr);
		ft_printf("rra\n");
	}
}

void	check_fastest_b(t_stack *ptr, int *arr, int size, int num)
{
	if (check_num_position_stack(arr, size, num))
	{
		rotate_b(ptr);
		ft_printf("rb\n");
	}
	else
	{
		reverse_rotate_b(ptr);
		ft_printf("rrb\n");
	}
}

void	check_fastest_with_counters_a(t_stack *ptr, int *arr, int size, int num)
{
	if (check_num_position_stack(arr, size, num))
	{
		rotate_a(ptr);
		ptr->rotate_a += 1;
	}
	else
	{
		reverse_rotate_a(ptr);
		ptr->reverse_rotate_a += 1;
	}
}

void	check_fastest_with_counters_b(t_stack *ptr, int *arr, int size, int num)
{
	if (check_num_position_stack(arr, size, num))
	{
		rotate_b(ptr);
		ptr->rotate_b += 1;
	}
	else
	{
		reverse_rotate_b(ptr);
		ptr->reverse_rotate_b += 1;
	}
}
