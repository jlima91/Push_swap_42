/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:36:07 by jlima             #+#    #+#             */
/*   Updated: 2022/06/15 10:20:57 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		ptr->initial_size_a = i;
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
	ptr->initial_size_a = i;
	free(split);
}

int	read_commands(t_stack *ptr)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!check_command(command, ptr))
		{
			free(command);
			return (0);
		}
		if (command == NULL)
			break ;
		free(command);
	}
	return (1);
}

int	check_command(char *str, t_stack *ptr)
{
	if (str == NULL)
		return (1);
	else if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		sa(ptr);
	else if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		sb(ptr);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(ptr);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(ptr);
	else if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		ra(ptr);
	else if (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		rb(ptr);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		rra(ptr);
	else if (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		rrb(ptr);
	else
		return (0);
	return (1);
}
