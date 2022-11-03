/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:40:34 by jlima             #+#    #+#             */
/*   Updated: 2022/06/03 11:22:41 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_intlen(const int *arr)
{
    unsigned count;

    count = 0;
    while (arr[count] != '\0')
        count++;
    return (count);
}