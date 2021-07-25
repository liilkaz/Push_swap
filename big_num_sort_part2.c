#include "push_swap.h"

int	ft_search_max(t_push *swap, int i)
{
	int	j;
	int	max;

	j = 0;
	max = swap->quantity + 1;
	while (swap->a[j] != 0 && j < swap->quantity)
	{
		if (swap->a[j] > swap->b[i] && swap->a[j] < max)
			max = swap->a[j];
		j++;
	}
	if (max == swap->quantity + 1)
	{
		j = 0;
		while (swap->a[j] != 0)
		{
			if (swap->a[j] < max)
				max = swap->a[j];
			j++;
		}
	}
	j = 0;
	while (swap->a[j] != max)
		j++;
	return (j);
}

void	ft_save(t_push *swap, int i, int sum_step)
{
	swap->mini_step = sum_step;
	swap->index_b = i;
	swap->index_a = ft_search_max(swap, i);
	swap->step_b = ft_top_b(swap, i);
	swap->step_a = ft_position(swap, i);
	swap->min_a = swap->minus_a;
	swap->min_b = swap->minus_b;
}

int	ft_sum_step_2(t_push *swap, int i)
{
	int	sum_step;

	sum_step = ft_top_b(swap, i) + ft_position(swap, i);
	if (swap->minus_a == swap->minus_b)
	{
		if (ft_top_b(swap, i) > ft_position(swap, i))
			sum_step = ft_top_b(swap, i);
		else
			sum_step = ft_position(swap, i);
	}
	return (sum_step);
}

void	ft_sum_step(t_push *swap)
{
	int	i;
	int	sum_step;

	while (swap->b[0] != 0)
	{
		i = -1;
		swap->mini_step = swap->quantity + 1;
		swap->index_b = -1;
		swap->index_a = -1;
		swap->step_a = swap->quantity;
		swap->step_b = swap->quantity;
		while (++i < swap->quantity && swap->b[i] != 0)
		{
			sum_step = ft_sum_step_2(swap, i);
			if (sum_step < swap->mini_step)
				ft_save(swap, i, sum_step);
		}
		ft_sort(swap);
	}
}

void	direction(t_push *swap, int item)
{
	if (item)
	{
		if (swap->min_b == -1)
			ft_rrb(swap);
		else
			ft_rb(swap);
	}
	else
	{
		if (swap->min_a == -1)
			ft_rra(swap);
		else
			ft_ra(swap);
	}
}
