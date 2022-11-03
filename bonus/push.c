/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:43:36 by jlima             #+#    #+#             */
/*   Updated: 2022/06/10 13:23:34 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *ptr)
{
	int	i;

	if (ptr->size_b == 0)
		return ;
	i = ptr->size_a;
	while (i > 0)
	{
		ptr->a[i] = ptr->a[i - 1];
		i--;
	}
	ptr->a[0] = ptr->b[0];
	ptr->size_a += 1;
	while (i < ptr->size_b)
	{
		ptr->b[i] = ptr->b[i + 1];
		i++;
	}
	ptr->size_b -= 1;
}

void	pb(t_stack *ptr)
{
	int	i;

	if (ptr->size_a == 0)
		return ;
	i = ptr->size_b;
	while (i > 0)
	{
		ptr->b[i] = ptr->b[i - 1];
		i--;
	}
	ptr->b[0] = ptr->a[0];
	ptr->size_b += 1;
	while (i < ptr->size_a)
	{
		ptr->a[i] = ptr->a[i + 1];
		i++;
	}
	ptr->size_a -= 1;
}
