/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:54:22 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:01:56 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argvs(char *argv[], int argc)
{
	unsigned int	i;
	long			num;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		if (ft_strlen(argv[i]) > 11)
			return (0);
		num = ft_long_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	if (!ft_isduplicate(argv))
		return (0);
	return (1);
}

void	init_stacks(t_stack *ptr, int argc, char *argv[], char *split[])
{
	unsigned int	i;

	i = 0;
	if (argc == 2)
		init_for_split(ptr, split);
	else
	{
		ptr->a = (int *)malloc(argc * sizeof(int *));
		if (!ptr->a)
			return ;
		while (argv[i + 1])
		{
			ptr->a[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		ptr->a[i] = '\0';
		ptr->size_a = i;
	}
	ptr->b = ft_calloc(ptr->size_a, sizeof(int *));
	if (!ptr->b)
		return ;
	ptr->size_b = 0;
}

void	init_for_split(t_stack *ptr, char *split[])
{
	unsigned int	i;

	i = 0;
	while (split[i])
		i++;
	ptr->a = (int *)malloc(i * sizeof(int *));
	if (!ptr->a)
		return ;
	i = 0;
	while (split[i])
	{
		ptr->a[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	ptr->a[i] = '\0';
	ptr->size_a = i;
	free(split);
}

void	initialize_counters(t_stack *ptr)
{
	ptr->rotate_a = 0;
	ptr->rotate_b = 0;
	ptr->reverse_rotate_a = 0;
	ptr->reverse_rotate_b = 0;
	ptr->count = 0;
}

void	pick_sort_option(t_stack *ptr)
{
	if (ptr->size_a == 3)
		sort_3(ptr);
	else if (ptr->size_a == 5)
		sort_5(ptr);
	else if (ptr->size_a <= 100)
		sort(ptr, 18);
	else if (ptr->size_a <= 500)
		sort(ptr, 40);
	else
		sort(ptr, (ptr->size_a / 20));
}
