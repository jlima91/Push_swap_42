/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isduplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:06:39 by jlima             #+#    #+#             */
/*   Updated: 2022/05/28 17:49:35 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isduplicate(char *arg[])
{
    unsigned int i;
    unsigned int d;

    i = 0;
    while (arg[i])
    {
        d = i + 1;
        while (arg[d])
        {
            if (ft_strcmp(arg[i], arg[d]) == 0)
                return (0);
            d++;
        }
        i++;
    }
    return (1);
}