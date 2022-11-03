/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:36:22 by jlima             #+#    #+#             */
/*   Updated: 2022/06/15 10:08:26 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	char	*commands;
	int		size_a;
	int		size_b;
	int		initial_size_a;
}			t_stack;

int			check_argvs(char *argv[], int argc);
void		init_stacks(t_stack *ptr, int argc, char *argv[], char *split[]);
void		init_for_split(t_stack *ptr, char *split[]);
int			read_commands(t_stack *ptr);
int			check_command(char *str, t_stack *ptr);
int			check_if_sorted(t_stack *ptr);

void		sa(t_stack *ptr);
void		sb(t_stack *ptr);
void		ss(t_stack *ptr);
void		pa(t_stack *ptr);
void		pb(t_stack *ptr);
void		ra(t_stack *ptr);
void		rb(t_stack *ptr);
void		rr(t_stack *ptr);
void		rra(t_stack *ptr);
void		rrb(t_stack *ptr);
void		rrr(t_stack *ptr);

#endif
