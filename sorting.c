#include "push_swap.h"

void	ft_quantity_three(t_push *swap)
{
	if (swap->a[0] > swap->a[1] && swap->a[1] < swap->a[2] \
	&& swap->a[2] > swap->a[0])
		ft_sa(swap);
	else if (swap->a[0] > swap->a[1] && swap->a[1] > swap->a[2] \
	&& swap->a[2] < swap->a[0])
	{
		ft_sa(swap);
		ft_rra(swap);
	}
	else if (swap->a[0] > swap->a[1] && swap->a[1] < swap->a[2] \
	&& swap->a[2] < swap->a[0])
		ft_ra(swap);
	else if (swap->a[0] < swap->a[1] && swap->a[1] > swap->a[2] \
	&& swap->a[2] > swap->a[0])
	{
		ft_sa(swap);
		ft_ra(swap);
	}
	else if (swap->a[0] < swap->a[1] && swap->a[1] > swap->a[2] \
	&& swap->a[2] < swap->a[0])
		ft_rra(swap);
}

void	ft_quantity_four(t_push *swap)
{
	int	i;

	i = 0;
	while (i < swap->quantity)
	{
		if (swap->a[0] > 1)
			ft_ra(swap);
		if (swap->a[0] <= 1)
			ft_pb(swap);
		i++;
	}
	ft_quantity_three(swap);
	ft_pa(swap);
}

void	ft_quantity_five(t_push *swap)
{
	int	i;

	i = 0;
	while (i < swap->quantity)
	{
		if (swap->a[0] > 2)
			ft_ra(swap);
		if (swap->a[0] <= 2)
			ft_pb(swap);
		i++;
	}
	ft_quantity_three(swap);
	if (swap->b[0] < swap->b[1])
		ft_sb(swap);
	ft_pa(swap);
	ft_pa(swap);
}

void	ft_quantity_more(t_push *swap)
{
	int	i;

	i = -1;
	swap->order = ft_calloc(swap->quantity, sizeof(int));
	if (!swap->order)
		return ;
	while (++i < swap->quantity)
		ft_count_for_quantity_more(swap, i);
	ft_moving(swap);
	free(swap->order);
	ft_final(swap);
}
