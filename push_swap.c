/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:43:54 by eelkabia          #+#    #+#             */
/*   Updated: 2024/12/16 22:02:17 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return (0);
// 	t_a_stack *a_stack;
// 	t_b_stack *b_stack;
// 	int i;

// 	i = 1;
// 	a_stack = NULL;
// 	b_stack = malloc(sizeof(t_b_stack));

// 	while (i < argc)
// 	{
// 		ft_push(&a_stack, ft_atoi(argv[argc - i]));
// 		i++;
// 	}
// 	push_stack_b(&a_stack,&b_stack);
// 	t_node *current_a = a_stack->top;
//     printf("Stack A:\n");
//     while (current_a)
//     {
//         printf("%d\n", current_a->value);
//         current_a = current_a->next;
//     }
// 	t_node *current_b = b_stack->top;
//     printf("Stack b:\n");
//     while (current_b)
//     {
//         printf("%d\n", current_b->value);
//         current_b = current_b->next;
//     }
// 	return (0);
// }

// Function to find the LIS and return its length
static int	find_lis(int arr[], int n, int lis[])
{
	int	*dp;
	int	*prev;
	int	length;
	int	max_index;
	int	k;
	int	temp;

	dp = (int *)malloc(n * sizeof(int));
	prev = (int *)malloc(n * sizeof(int));
	length = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		prev[i] = -1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}
	max_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (dp[i] > dp[max_index])
		{
			max_index = i;
		}
	}
	k = max_index;
	while (k >= 0)
	{
		lis[length++] = arr[k];
		k = prev[k];
	}
	free(dp);
	free(prev);
	// Reverse the LIS array to get the correct order
	for (int i = 0; i < length / 2; i++)
	{
		temp = lis[i];
		lis[i] = lis[length - i - 1];
		lis[length - i - 1] = temp;
	}
	return (length);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	t_a_stack *a_stack = malloc(sizeof(t_a_stack));
	t_b_stack *b_stack = malloc(sizeof(t_b_stack));
	a_stack->top = NULL;
	a_stack->size = 0;
	b_stack->top = NULL;
	b_stack->size = 0;

	int n = argc - 1;
	int arr[n];
	int i = 0;
	while (i < n)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		ft_push(&a_stack, arr[n - i - 1]); // Push to a_stack in reverse order
		i++;
	}

	int lis[n];
	int length = find_lis(arr, n, lis);

	i = 0;
	while (i < n)
	{
		int is_in_lis = 0;
		for (int j = 0; j < length; j++)
		{
			if (arr[i] == lis[j])
			{
				is_in_lis = 1;
				break ;
			}
		}
		if (!is_in_lis)
		{
			push_stack_b(&a_stack, &b_stack);
		}
		else
		{
			rotate_stack_a(&a_stack);
		}
		i++;
	}

	// Merge the b_stack back to a_stack in sorted order
	while (b_stack->size > 0)
	{
		push_stack_a(&a_stack, &b_stack);
	}

	// Print stack A
	t_node *current_a = a_stack->top;
	printf("Stack A (sorted):\n");
	while (current_a)
	{
		printf("%d\n", current_a->value);
		current_a = current_a->next;
	}

	// Free allocated memory
	free(a_stack);
	free(b_stack);

	return (0);
}