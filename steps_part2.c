#include "push_swap.h"

void	ft_rra_rrb_rrr(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 9)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 10 && l == 1)
		{
			swap->instruction[index] = 11;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 9 \
				&& swap->instruction[i] != 10 && swap->instruction[i] != 11)
			l = 0;
		i++;
	}
}

void	ft_rrb_rra_rrr(t_push *swap, int *retry)
{
	int	i;
	int	index;
	int	l;

	i = 0;
	l = 0;
	while (i < swap->commands)
	{
		if (swap->instruction[i] == 10)
		{
			index = i;
			l = 1;
		}
		else if (swap->instruction[i] == 9 && l == 1)
		{
			swap->instruction[index] = 11;
			swap->instruction[i] = 0;
			l = 0;
			(*retry)++;
		}
		else if (swap->instruction[i] != 0 && swap->instruction[i] != 9 \
				&& swap->instruction[i] != 10 && swap->instruction[i] != 11)
			l = 0;
		i++;
	}
}

void	change_instruct(int instruction)
{
	if (instruction == 1)
		write (1, "sa\n", 3);
	else if (instruction == 2)
		write (1, "sb\n", 3);
	else if (instruction == 3)
		write (1, "ss\n", 3);
	else if (instruction == 4)
		write (1, "pa\n", 3);
	else if (instruction == 5)
		write (1, "pb\n", 3);
	else if (instruction == 6)
		write (1, "ra\n", 3);
	else if (instruction == 7)
		write (1, "rb\n", 3);
	else if (instruction == 8)
		write (1, "rr\n", 3);
	else if (instruction == 9)
		write (1, "rra\n", 4);
	else if (instruction == 10)
		write (1, "rrb\n", 4);
	else if (instruction == 11)
		write (1, "rrr\n", 4);
}

void	ft_finish(t_push *swap)
{
	int	i;

	i = -1;
	while (++i < swap->commands)
		change_instruct(swap->instruction[i]);
}
