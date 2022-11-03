/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:39 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 08:45:57 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (last occurence)
**
** DESCRIPTION:
** 		The strrchr() function locates the last occurrence of c (converted to a
**	char) in the string s.  If c is `\0', strrchr() locates the terminating
**	`\0'.
*/

#include "libft.h"

static int	ft_check_doubles(const char *cpy, int c, int i)
{
	i++;
	while (cpy[i] != '\0')
	{
		if (cpy[i] == (unsigned char)c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*cpy;

	cpy = str;
	i = 0;
	if (((unsigned char)c) == '\0')
		return (((char *)str) + ft_strlen(str));
	while (cpy[i] != '\0')
	{
		if (cpy[i] == (unsigned char)c)
		{
			if (ft_check_doubles(cpy, c, i) == 0)
				return ((char *)str);
			i++;
			str++;
		}
		else
		{
			i++;
			str++;
		}
	}
	return (NULL);
}
