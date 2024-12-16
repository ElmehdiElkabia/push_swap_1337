/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:45:57 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 21:46:10 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack_a(t_a_stack **a_stack)
{
	t_node	*temp;
	t_node	*last;

	if ((*a_stack)->size < 2)
		return ;
	temp = (*a_stack)->top;
	last = (*a_stack)->top;
	while (last->next->next)
		last = last->next;
	(*a_stack)->top = last->next;
	last->next = NULL;
	(*a_stack)->top->next = temp;
}

void	reverse_rotate_stack_b(t_b_stack **b_stack)
{
	t_node	*temp;
	t_node	*last;

	if ((*b_stack)->size < 2)
		return ;
	temp = (*b_stack)->top;
	last = (*b_stack)->top;
	while (last->next->next)
		last = last->next;
	(*b_stack)->top = last->next;
	last->next = NULL;
	(*b_stack)->top->next = temp;
}

void	reverse_rotate_stack_ab(t_a_stack **a_stack, t_b_stack **b_stack)
{
	reverse_rotate_stack_a(a_stack);
	reverse_rotate_stack_b(b_stack);
}