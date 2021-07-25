#include "push_swap.h"
#include <stdio.h>

void	ft_init(int *a, int *b, int quanyity, t_push *swap)
{
	swap->a = a;
	swap->b = b;
	swap->quantity = quanyity;
	swap->count = 0;
	swap->order = NULL;
	swap->step_a = quanyity;
	swap->step_b = quanyity;
	swap->mini_step = quanyity;
	swap->minus_a = 1;
	swap->minus_b = 1;
	swap->min_a = 1;
	swap->min_b = 1;
	swap->index_b = -1;
	swap->index_a = -1;
	swap->commands = 0;
}

void	ft_sa(t_push *swap)
{
	int	tmp;

	tmp = swap->a[0];
	swap->a[0] = swap->a[1];
	swap->a[1] = tmp;
	swap->instruction[swap->commands++] = 1;
}

void	ft_sb(t_push *swap)
{
	int	tmp;

	tmp = swap->b[0];
	swap->b[0] = swap->b[1];
	swap->b[1] = tmp;
	swap->instruction[swap->commands++] = 2;
}

void	ft_ss(t_push *swap)
{
	ft_sa(swap);
	ft_sb(swap);
	swap->instruction[swap->commands++] = 3;
}
