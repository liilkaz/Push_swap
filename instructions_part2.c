#include "push_swap.h"

void	ft_pa(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	while (swap->a[i] !=0 && i < swap->quantity)
		i++;
	while (i != 0)
	{
		j = i - 1;
		swap->a[j + 1] = swap->a[j];
		i--;
	}
	swap->a[0] = swap->b[0];
	i = 1;
	while (swap->b[i] !=0 && i < swap->quantity)
	{
		swap->b[i - 1] = swap->b[i];
		i++;
	}
	swap->b[i - 1] = 0;
	swap->instruction[swap->commands++] = 4;
}

void	ft_pb(t_push *swap)
{
	int	i;
	int	j;

	i = 0;
	while (swap->b[i] !=0 && i < swap->quantity)
		i++;
	while (i != 0)
	{
		j = i - 1;
		swap->b[j + 1] = swap->b[j];
		i--;
	}
	swap->b[0] = swap->a[0];
	i = 1;
	while (swap->a[i] !=0 && i < swap->quantity)
	{
		swap->a[i - 1] = swap->a[i];
		i++;
	}
	swap->a[i - 1] = 0;
	swap->instruction[swap->commands++] = 5;
}

void	ft_ra(t_push *swap)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = swap->a[0];
	while (swap->a[i] !=0 && i < swap->quantity)
	{
		swap->a[i - 1] = swap->a[i];
		i++;
	}
	swap->a[i - 1] = tmp;
	swap->instruction[swap->commands++] = 6;
}

void	ft_rb(t_push *swap)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = swap->b[0];
	while (swap->b[i] !=0 && i < swap->quantity)
	{
		swap->b[i - 1] = swap->b[i];
		i++;
	}
	swap->b[i - 1] = tmp;
	swap->instruction[swap->commands++] = 7;
}
