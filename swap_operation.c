/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:45:09 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 21:45:24 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_a_stack **a_stack)
{
	t_node	*temp;

	if ((*a_stack)->size < 2)
		return ;
	temp = (*a_stack)->top;
	(*a_stack)->top = temp->next;
	temp->next = (*a_stack)->top->next;
	(*a_stack)->top->next = temp;
}

void	swap_stack_b(t_b_stack **b_stack)
{
	t_node	*temp;

	if ((*b_stack)->size < 2)
		return ;
	temp = (*b_stack)->top;
	(*b_stack)->top = temp->next;
	temp->next = (*b_stack)->top->next;
	(*b_stack)->top->next = temp;
}

void	swap_stack_ab(t_a_stack **a_stack, t_b_stack **b_stack)
{
	swap_stack_a(a_stack);
	swap_stack_b(b_stack);
}