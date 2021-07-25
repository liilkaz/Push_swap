#include "push_swap.h"

void	ft_reduction_of_steps(t_push *swap)
{
	int	retry;

	retry = 1;
	while (retry != 0)
	{
		retry = 0;
		ft_sa_sb_ss(swap, &retry);
		ft_sb_sa_ss(swap, &retry);
		ft_ra_rb_rr(swap, &retry);
		ft_rb_ra_rr(swap, &retry);
		ft_rra_rrb_rrr(swap, &retry);
		ft_rrb_rra_rrr(swap, &retry);
	}
}

void	ft_sa_sb_ss(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 1)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 2 && l == 1)
		{
			swap->instruction[index] = 3;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 1 \
				&& swap->instruction[i] != 2 && swap->instruction[i] != 3)
			l = 0;
		i++;
	}
}

void	ft_sb_sa_ss(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 2)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 1 && l == 1)
		{
			swap->instruction[index] = 3;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 1 \
				&& swap->instruction[i] != 2 && swap->instruction[i] != 3)
			l = 0;
		i++;
	}
}

void	ft_ra_rb_rr(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 6)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 7 && l == 1)
		{
			swap->instruction[index] = 8;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 6 \
				&& swap->instruction[i] != 7 && swap->instruction[i] != 8)
			l = 0;
		i++;
	}
}

void	ft_rb_ra_rr(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 7)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 6 && l == 1)
		{
			swap->instruction[index] = 8;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 6 \
				&& swap->instruction[i] != 7 && swap->instruction[i] != 8)
			l = 0;
		i++;
	}
}
