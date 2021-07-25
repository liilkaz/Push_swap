#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_push
{
	int	*a;
	int	*b;
	int	quantity;
	int	*order;
	int	count;
	int	step_a;
	int	step_b;
	int	mini_step;
	int	minus_a;
	int	minus_b;
	int	min_a;
	int	min_b;
	int	index_a;
	int	index_b;
	int	instruction[10000];
	int	commands;
}	t_push;

void	ft_init(int *a, int *b, int quanyity, t_push *swap);
void	ft_sa(t_push *swap);
void	ft_sb(t_push *swap);
void	ft_ss(t_push *swap);
void	ft_pa(t_push *swap);
void	ft_pb(t_push *swap);
void	ft_ra(t_push *swap);
void	ft_rb(t_push *swap);
void	ft_rr(t_push *swap);
void	ft_rra(t_push *swap);
void	ft_rrb(t_push *swap);
void	ft_rrr(t_push *swap);
void	ft_algorithms(t_push *swap);
int		ft_error(char *str);
void	ft_quantity_three(t_push *swap);
void	ft_quantity_five(t_push *swap);
void	ft_quantity_four(t_push *swap);
void	ft_quantity_more(t_push *swap);
void	ft_count_for_quantity_more(t_push *swap, int i);
void	ft_moving(t_push *swap);
int		ft_top_b(t_push *swap, int i);
int		ft_position(t_push *swap, int i);
int		ft_search_max(t_push *swap, int i);
void	ft_sum_step(t_push *swap);
void	ft_sort(t_push *swap);
void	direction(t_push *swap, int item);
void	ft_final(t_push *swap);
void	ft_reduction_of_steps(t_push *swap);
void	ft_rrr_rr(t_push *swap);
void	ft_sa_sb_ss(t_push *swap, int *retry);
void	ft_sb_sa_ss(t_push *swap, int *retry);
void	ft_ra_rb_rr(t_push *swap, int *retry);
void	ft_rb_ra_rr(t_push *swap, int *retry);
void	ft_rra_rrb_rrr(t_push *swap, int *retry);
void	ft_rrb_rra_rrr(t_push *swap, int *retry);
void	ft_finish(t_push *swap);
int		ft_done(t_push *swap);

int		*ft_convert(int quantity, char **argv);
int		*ft_convert_part2(int *a, int quantity);
int		ft_mistakes(char **argv, int quantity);
int		get_next_line(char **line);

#endif
