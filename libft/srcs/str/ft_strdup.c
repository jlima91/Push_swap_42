/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:47:53 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 10:09:26 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <string.h>
** SYNOPSIS: save a copy of a string (with malloc)
**
** DESCRIPTION:
** 		The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
*/

char	*ft_strdup(const char *s)
{
	int		i;
	char	*array;

	array = malloc(ft_strlen(s) + 1);
	if (!(array))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
