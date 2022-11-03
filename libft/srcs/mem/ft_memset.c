/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:36:20 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 10:20:09 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*array;
	unsigned char	temp;

	i = 0;
	temp = (char)c;
	if (len > 0)
	{
		array = str;
		while (i < len)
		{
			array[i] = temp;
			i++;
		}
	}
	return (str);
}
