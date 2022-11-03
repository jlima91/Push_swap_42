/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:47:53 by jlima             #+#    #+#             */
/*   Updated: 2022/06/03 17:29:56 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <string.h>
** SYNOPSIS: save a copy of a array of int (with malloc)
**
** DESCRIPTION:
** 		The intdup() function allocates sufficient memory for a copy of the
**	array of ints arr, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
*/

int	*ft_intup(const int *arr, int n)
{
	int		i;
	int	*array;

	array = malloc(n + 1);
	if (!(array))
		return (0);
	i = 0;
	while (i < n)
	{
		array[i] = arr[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}