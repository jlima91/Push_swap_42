/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:13:56 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:02:08 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number_for_smaller_route(int (*arr)[2], int count)
{
	int	c;
	int	smallest;

	smallest = arr[0][1];
	c = 1;
	while (c < count)
	{
		if (smallest > arr[c][1])
			smallest = arr[c][1];
		c++;
	}
	c = 0;
	while (arr[c][1] != smallest)
		c++;
	smallest = arr[c][0];
	return (smallest);
}

void	check_counters(t_stack *ptr)
{
	while (ptr->rotate_a != 0 && ptr->rotate_b != 0)
	{
		ptr->rotate_a -= 1;
		ptr->rotate_b -= 1;
		ft_printf("rr\n");
	}
	while (ptr->reverse_rotate_a != 0 && ptr->reverse_rotate_b != 0)
	{
		ptr->reverse_rotate_a -= 1;
		ptr->reverse_rotate_b -= 1;
		ft_printf("rrr\n");
	}
	check_remaining_counters(ptr);
}

void	check_remaining_counters(t_stack *ptr)
{
	while (ptr->rotate_a)
	{
		ptr->rotate_a -= 1;
		ft_printf("ra\n");
	}
	while (ptr->rotate_b)
	{
		ptr->rotate_b -= 1;
		ft_printf("rb\n");
	}
	while (ptr->reverse_rotate_a)
	{
		ptr->reverse_rotate_a -= 1;
		ft_printf("rra\n");
	}
	while (ptr->reverse_rotate_b)
	{
		ptr->reverse_rotate_b -= 1;
		ft_printf("rrb\n");
	}
}

int	get_num_to_push(t_stack *ptr, int count)
{
	int	num;
	int	(*chunk)[2];

	chunk = array_of_smallest(ptr->a, ptr->size_a, count);
	chunk = pick_better_num_to_push(chunk, ptr->a, ptr->size_a, count);
	num = get_number_for_smaller_route(chunk, count);
	free(chunk);
	return (num);
}

void	*pick_better_num_to_push(int (*array)[2], int *arr, int size, int count)
{
	int	mid;
	int	i;
	int	c;

	c = 0;
	while (c < count)
	{
		i = 0;
		while (array[c][0] != arr[i])
			i++;
		mid = size / 2;
		if (i > mid)
			array[c][1] = (size - i);
		else
			array[c][1] = i;
		c++;
	}
	return (array);
}
