/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:33:21 by jlima             #+#    #+#             */
/*   Updated: 2022/05/31 17:21:58 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	ft_identifiers(t_ident *ptr, const char *str, int i)
{
	if (str[i] == 'c')
		ft_print_char(ptr);
	if (str[i] == 'd' || str[i] == 'i')
		ft_print_int(ptr);
	if (str[i] == 'u')
		ft_print_unsigned(ptr);
	if (str[i] == 's')
		ft_print_str(ptr);
	if (str[i] == 'p')
		ft_print_pointer(ptr);
	if (str[i] == 'x' || str[i] == 'X')
	{
		if (str[i] == 'x')
			ptr->x = 1;
		ft_print_hex(ptr, str, i);
	}
	if (str[i] == '%')
		ft_print_perc(ptr);
}

static t_ident	*ft_initialize_t_ident_args(t_ident *ptr)
{
	ptr->x = 0;
	ptr->count = 0;
	return (ptr);
}

static int	ft_print_evaluate(t_ident *ptr, const char *str, int i)
{
	ft_identifiers(ptr, str, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_ident	*ptr;
	int		i;
	int		total_len;

	ptr = (t_ident *)malloc(sizeof(t_ident));
	ft_initialize_t_ident_args(ptr);
	va_start(ptr->args, format);
	i = 0;
	total_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = ft_print_evaluate(ptr, format, i + 1);
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr->args);
	total_len += ptr->count;
	free(ptr);
	return (total_len);
}
