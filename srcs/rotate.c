/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:44:28 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:01:42 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *ptr)
{
	int	i;
	int	swap;

	swap = ptr->a[0];
	i = 1;
	while (i < ptr->size_a)
	{
		ptr->a[i - 1] = ptr->a[i];
		i++;
	}
	ptr->a[ptr->size_a - 1] = swap;
}

void	rotate_b(t_stack *ptr)
{
	int	i;
	int	swap;

	swap = ptr->b[0];
	i = 1;
	while (i < ptr->size_b)
	{
		ptr->b[i - 1] = ptr->b[i];
		i++;
	}
	ptr->b[ptr->size_b - 1] = swap;
}
