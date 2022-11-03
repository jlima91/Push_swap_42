/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:43:25 by jlima             #+#    #+#             */
/*   Updated: 2022/05/28 18:51:55 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: create new list
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a new element. The variable
**	’content’ is initialized with the value of the parameter ’content’. The
**	variable ’next’ is initialized to NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = ((t_list *)malloc(sizeof(*lst)));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
