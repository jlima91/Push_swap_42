/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:42:51 by jlima             #+#    #+#             */
/*   Updated: 2022/11/03 13:01:51 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *ptr)
{
	int	swap;

	if (ptr->size_a <= 1)
		return ;
	swap = ptr->a[0];
	ptr->a[0] = ptr->a[1];
	ptr->a[1] = swap;
	ft_printf("sa\n");
}

void	swap_b(t_stack *ptr)
{
	int	swap;

	if (ptr->size_b <= 1)
		return ;
	swap = ptr->b[0];
	ptr->b[0] = ptr->b[1];
	ptr->b[1] = swap;
	ft_printf("sb\n");
}

void	ss(t_stack *ptr)
{
	swap_a(ptr);
	swap_b(ptr);
	ft_printf("ss\n");
}
