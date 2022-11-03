/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:58:59 by jlima             #+#    #+#             */
/*   Updated: 2022/05/27 13:03:17 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (first occurrence)
**
** DESCRIPTION:
** 		The strchr() function locates the first occurrence of c (converted to a
**	char) in the string pointed to by s.  The terminating null character is
**	considered to be part of the string; therefore if c is `\0', the func-
**	tions locate the terminating `\0'.
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (((unsigned char)c) == '\0')
		return (((char *)str) + ft_strlen(str));
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		else
			str++;
	}
	return (NULL);
}
