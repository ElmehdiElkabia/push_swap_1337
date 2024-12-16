/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:43:54 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 17:49:50 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_a_stack *a_stack;
	t_b_stack *b_stack;
	int i;

	i = 1;
	a_stack = NULL;
	b_stack = malloc(sizeof(t_b_stack));

	while (i < argc)
	{
		ft_push(&a_stack, ft_atoi(argv[i]));
		i++;
	}
	push_stack_b(&a_stack, &b_stack);
	//push_stack_b(&a_stack, &b_stack);
	t_node *current = b_stack->top;
	while (current != NULL)
	{
		printf("stack b ->%d\n", current->value);
		current = current->next;
	}
	//push_stack_b(&a_stack, &b_stack);
	//push_stack_a(&a_stack, &b_stack);
	t_node *current1 = a_stack->top;
	while (current1 != NULL)
	{
		printf("stack a ->%d\n", current1->value);
		current1 = current1->next;
	}
	return (0);
}