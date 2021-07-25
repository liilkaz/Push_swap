#include "push_swap.h"

void	ft_rr(t_push *swap)
{
	ft_ra(swap);
	ft_rb(swap);
	swap->instruction[swap->commands++] = 8;
}

void	ft_rra(t_push *swap)
{
	int	tmp;
	int	i;

	i = 0;
	while (swap->a[i] !=0 && i < swap->quantity)
		i++;
	tmp = swap->a[i - 1];
	i--;
	while (i !=0)
	{
		swap->a[i] = swap->a[i - 1];
		i--;
	}
	swap->a[0] = tmp;
	swap->instruction[swap->commands++] = 9;
}

void	ft_rrb(t_push *swap)
{
	int	tmp;
	int	i;

	i = 0;
	while (swap->b[i] !=0 && i < swap->quantity)
		i++;
	tmp = swap->b[i - 1];
	i--;
	while (i !=0)
	{
		swap->b[i] = swap->b[i - 1];
		i--;
	}
	swap->b[0] = tmp;
	swap->instruction[swap->commands++] = 10;
}

void	ft_rrr(t_push *swap)
{
	ft_rra(swap);
	ft_rrb(swap);
	swap->instruction[swap->commands++] = 11;
}
