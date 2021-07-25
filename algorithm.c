#include "push_swap.h"
#include <stdio.h>

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	ft_done(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < swap->quantity)
	{
		if (swap->a[i] != j)
			return (0);
		j++;
		i++;
	}
	return (1);
}

void	ft_algorithms(t_push *swap)
{
	if (swap->quantity == 2)
		ft_sa(swap);
	if (swap->quantity == 3)
		ft_quantity_three(swap);
	if (swap->quantity == 4)
		ft_quantity_four(swap);
	if (swap->quantity == 5)
		ft_quantity_five(swap);
	if (swap->quantity > 5)
		ft_quantity_more(swap);
}

void	ft_sort(t_push *swap)
{
	int	i;

	i = -1;
	if (swap->index_b > 0)
	{
		while (++i < swap->step_b)
			direction(swap, 1);
	}
	i = -1;
	if (swap->index_b == 0)
	{
		if (swap->index_a > 0)
		{
			while (++i < swap->step_a)
				direction(swap, 0);
		}
		ft_pa(swap);
	}
}

void	ft_final(t_push *swap)
{
	int	i;

	i = 0;
	while (swap->a[i] < swap->quantity && swap->a[0] != 1)
	{
		i++;
	}
	if (swap->a[i] <= (swap->quantity / 2))
	{
		while (swap->a[0] != 1)
			ft_rra(swap);
	}
	else if (swap->a[i] > (swap->quantity / 2))
	{
		while (swap->a[0] != 1)
			ft_ra(swap);
	}
	ft_reduction_of_steps(swap);
}
