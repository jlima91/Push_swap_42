/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:45:19 by jlima             #+#    #+#             */
/*   Updated: 2022/06/10 13:23:55 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *ptr)
{
	int	i;
	int	swap;

	i = ptr->size_a - 1;
	swap = ptr->a[i];
	while (i > 0)
	{
		ptr->a[i] = ptr->a[i - 1];
		i--;
	}
	ptr->a[0] = swap;
}

void	rrb(t_stack *ptr)
{
	int	i;
	int	swap;

	i = ptr->size_b - 1;
	swap = ptr->b[i];
	while (i > 0)
	{
		ptr->b[i] = ptr->b[i - 1];
		i--;
	}
	ptr->b[0] = swap;
}

void	rrr(t_stack *ptr)
{
	rra(ptr);
	rrb(ptr);
}
