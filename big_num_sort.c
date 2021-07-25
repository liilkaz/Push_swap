#include "push_swap.h"

int	count_iter(t_push *swap, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (i < swap->quantity && j < swap->quantity)
	{
		if (swap->a[i] >= swap->a[j])
			j++;
		else if (swap->a[i] < swap->a[j])
		{
			count++;
			i = j;
		}
	}
	return (count);
}

void	ft_count_for_quantity_more(t_push *swap, int isave)
{
	int	i;
	int	j;
	int	k;
	int	count;

	k = 0;
	count = count_iter(swap, isave);
	if (count > swap->count)
	{
		swap->count = count;
		i = isave;
		j = i;
		swap->order[k++] = swap->a[i];
		while (i < swap->quantity && j < swap->quantity && k < count + 1)
		{
			if (swap->a[i] >= swap->a[j])
				j++;
			else if (swap->a[i] < swap->a[j])
			{
				swap->order[k] = swap->a[j];
				i = j;
				k++;
			}
		}
	}
}

void	ft_moving(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < swap->quantity)
	{
		if (swap->a[0] == swap->order[j])
		{
			ft_ra(swap);
			j++;
		}
		else
			ft_pb(swap);
		i++;
	}
	ft_sum_step(swap);
}

int	ft_top_b(t_push *swap, int i)
{
	int	l;
	int	step;
	int	double_step;
	int	mini_step;

	l = 0;
	double_step = 0;
	while (swap->b[l++] != 0)
		double_step++;
	step = i - 0;
	double_step = -(double_step - i);
	mini_step = 0;
	if (double_step < 0)
		double_step = double_step * (-1);
	if (step > double_step)
	{
		mini_step = double_step;
		swap->minus_b = -1;
	}
	else if (step <= double_step)
	{
		mini_step = step;
		swap->minus_b = 1;
	}
	return (mini_step);
}

int	ft_position(t_push *swap, int i)
{
	int	l;
	int	pos;
	int	pos_f;
	int	step_down;

	l = 0;
	step_down = 0;
	pos_f = 0;
	while (swap->a[l++] != 0)
		step_down++;
	pos = ft_search_max(swap, i);
	step_down = -(step_down - pos);
	if (step_down < 0)
		step_down = -step_down;
	if (pos > step_down)
	{
		pos_f = step_down;
		swap->minus_a = -1;
	}
	else if (pos <= step_down)
	{
		pos_f = pos;
		swap->minus_a = 1;
	}
	return (pos_f);
}
