/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:45:19 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:01:36 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *ptr)
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

void	reverse_rotate_b(t_stack *ptr)
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
