/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:38:45 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:17:08 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nearly_sorted(t_stack *stx)
{
	int	i;
	int	j;

	j = find_high(stx);
	i = j + 1;
	if (i == stx->a_len)
		i = 0;
	while (i != j)
	{
		if (i > 0)
		{
			if (stx->a[i] > stx->a[i - 1])
				return (0);
		}
		else if (stx->a[i] > stx->a[stx->a_len - 1])
			return (0);
		i++;
		if (i == stx->a_len)
			i = 0;
	}
	return (1);
}

int	ft_sorted(t_stack *stx)
{
	int	i;

	i = 1;
	while (i < stx->a_len)
	{
		if (stx->a[i] > stx->a[i - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	push_to_a(t_stack *stx)
{
	if (stx->a_up_down == UP && stx->b_up_down == UP)
		up_up(stx);
	if (stx->a_up_down == DOWN && stx->b_up_down == DOWN)
		down_down(stx);
	while (stx->move_a > 0)
	{
		if (stx->a_up_down == UP)
			ra(stx);
		else if (stx->a_up_down == DOWN)
			rra(stx);
		stx->move_a -= 1;
	}
	while (stx->move_b > 0)
	{
		if (stx->b_up_down == UP)
			rb(stx);
		else if (stx->b_up_down == DOWN)
			rrb(stx);
		stx->move_b -= 1;
	}
	pa(stx);
}

void	ft_sort(t_stack *stx)
{
	t_move	mov;

	while (stx->b_len > 0)
	{
		find_best(stx, &mov);
		push_to_a(stx);
	}
}
