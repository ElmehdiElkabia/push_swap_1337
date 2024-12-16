/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:06 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 17:33:57 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_a_stack
{
	t_node			*top;
	int				size;
}					t_a_stack;

typedef struct s_b_stack
{
	t_node			*top;
	int				size;
}					t_b_stack;

void	ft_push(t_a_stack **a_stack, int value);
int		ft_atoi(const char *str);
void	push_stack_a(t_a_stack **a_stack, t_b_stack **b_stack);
void	push_stack_b(t_a_stack **a_stack, t_b_stack **b_stack);

#endif