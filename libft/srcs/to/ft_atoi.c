/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:10:06 by jlima             #+#    #+#             */
/*   Updated: 2022/06/01 09:42:42 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	check;
	int	value;
	int	i;
	int	n;

	check = 0;
	value = 0;
	i = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (check == 1)
			return (value * n);
		if (str[i] == '-')
			n = n * -1;
		check = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = (value * 10) + (str[i++] - 48);
	return (value * n);
}
