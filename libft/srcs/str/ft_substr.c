/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:18:00 by jlima             #+#    #+#             */
/*   Updated: 2022/05/04 15:57:10 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_str;

	j = start;
	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	sub_str = malloc(len + 1);
	if (!(sub_str))
		return (NULL);
	i = 0;
	while (j < ft_strlen(s) && len > i)
		sub_str[i++] = s[j++];
	sub_str[i] = '\0';
	return (sub_str);
}
