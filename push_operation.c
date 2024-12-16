/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:30:23 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 17:56:08 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack_a(t_a_stack **a_stack, t_b_stack **b_stack)
{
	t_node	*tmp;

	if ((*b_stack)->size == 0)
		return ;
	tmp = (*b_stack)->top;
	(*b_stack)->top = (*b_stack)->top->next;
	tmp->next = (*a_stack)->top;
	(*a_stack)->top = tmp;
	(*a_stack)->size++;
	(*b_stack)->size--;
}

void	push_stack_b(t_a_stack **a_stack, t_b_stack **b_stack)
{
	t_node *tmp;

	if ((*a_stack)->size == 0)
		return ;
	tmp = (*a_stack)->top;
	(*a_stack)->top = (*a_stack)->top->next;
	tmp->next = (*b_stack)->top;
	(*b_stack)->top = tmp;
	(*b_stack)->size++;
	(*a_stack)->size--;
}