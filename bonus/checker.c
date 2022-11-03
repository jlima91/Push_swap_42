/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:35:10 by jlima             #+#    #+#             */
/*   Updated: 2022/06/15 10:13:14 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_if_sorted(t_stack *ptr)
{
	unsigned int	i;

	i = ptr->size_a;
	while (i > 1)
	{
		if (ptr->a[i - 1] > ptr->a[i - 2])
			i--;
		else
			return (0);
	}
	if (ptr->initial_size_a != ptr->size_a)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**split;
	t_stack	*ptr;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!check_argvs(split, argc))
			return (ft_printf("Error\n"));
	}
	if (!check_argvs(argv, argc) && argc > 2)
		return (ft_printf("Error\n"));
	ptr = (t_stack *)malloc(sizeof(t_stack));
	init_stacks(ptr, argc, argv, split);
	if (!read_commands(ptr))
		return (ft_printf("Error\n"));
	if (check_if_sorted(ptr))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(ptr->a);
	free(ptr->b);
	free(ptr);
	return (0);
}
