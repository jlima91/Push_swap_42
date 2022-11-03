/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:52:30 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 09:01:05 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*cdest;
	const char		*csrc;

	cdest = dest;
	csrc = src;
	i = 0;
	if (!dest && !src)
		return (0);
	cdest = dest;
	csrc = src;
	while ((i < n))
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
