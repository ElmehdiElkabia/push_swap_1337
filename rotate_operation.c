/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:45:31 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 21:45:49 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_a_stack **a_stack)
{
	t_node	*temp;
	t_node	*last;

	if ((*a_stack)->size < 2)
		return ;
	temp = (*a_stack)->top;
	last = (*a_stack)->top;
	while (last->next)
		last = last->next;
	(*a_stack)->top = temp->next;
	temp->next = NULL;
	last->next = temp;
}

void	rotate_stack_b(t_b_stack **b_stack)
{
	t_node	*temp;
	t_node	*last;

	if ((*b_stack)->size < 2)
		return ;
	temp = (*b_stack)->top;
	last = (*b_stack)->top;
	while (last->next)
		last = last->next;
	(*b_stack)->top = temp->next;
	temp->next = NULL;
	last->next = temp;
}

void	rotate_stack_ab(t_a_stack **a_stack, t_b_stack **b_stack)
{
	rotate_stack_a(a_stack);
	rotate_stack_b(b_stack);
}