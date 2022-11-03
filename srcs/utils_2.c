/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:00:37 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:02:00 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_smallest(int *arr, int size)
{
	int	c;
	int	smallest;

	smallest = arr[0];
	c = 1;
	while (c < size)
	{
		if (smallest > arr[c])
			smallest = arr[c];
		c++;
	}
	return (smallest);
}

void	*array_of_smallest(int *arr, int size, int count)
{
	int	c;
	int	i;
	int	smallest;
	int	checker;
	int	(*array)[2];

	array = malloc(sizeof * array * count);
	if (!array)
		return (0);
	checker = INT_MIN;
	i = 0;
	while (i < count)
	{
		c = 0;
		smallest = INT_MAX;
		while (c < size)
		{
			if (smallest > arr[c] && arr[c] > checker)
				smallest = arr[c];
			c++;
		}
		array[i++][0] = smallest;
		checker = smallest;
	}
	return (array);
}

int	next_smallest(int *arr, int size, int smallest)
{
	int	c;
	int	next_smallest;

	next_smallest = INT_MAX;
	c = size - 1;
	while (c >= 0)
	{
		if (next_smallest > arr[c] && arr[c] > smallest)
			next_smallest = arr[c];
		c--;
	}
	return (next_smallest);
}

int	previous_smallest(int *arr, int size, int smallest)
{
	int	c;
	int	previous_smallest;

	previous_smallest = INT_MIN;
	c = 0;
	while (c < size)
	{
		if (previous_smallest < arr[c] && arr[c] < smallest)
			previous_smallest = arr[c];
		c++;
	}
	return (previous_smallest);
}

int	check_highest(int *arr, int size)
{
	int	c;
	int	highest;

	highest = arr[0];
	c = 1;
	while (c < size)
	{
		if (highest < arr[c])
			highest = arr[c];
		c++;
	}
	return (highest);
}
