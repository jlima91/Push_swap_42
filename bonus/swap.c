/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:42:51 by jlima             #+#    #+#             */
/*   Updated: 2022/06/10 13:24:11 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *ptr)
{
	int	swap;

	if (ptr->size_a <= 1)
		return ;
	swap = ptr->a[0];
	ptr->a[0] = ptr->a[1];
	ptr->a[1] = swap;
}

void	sb(t_stack *ptr)
{
	int	swap;

	if (ptr->size_b <= 1)
		return ;
	swap = ptr->b[0];
	ptr->b[0] = ptr->b[1];
	ptr->b[1] = swap;
}

void	ss(t_stack *ptr)
{
	sa(ptr);
	sb(ptr);
}
