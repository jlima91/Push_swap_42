/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:34:01 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 13:35:00 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	if (nelem + elsize < nelem)
		return (0);
	ptr = malloc((nelem * elsize));
	if (!(ptr))
		return (0);
	ft_bzero(ptr, (nelem * elsize));
	return (ptr);
}
