#include "push_swap.h"

void	ft_commands(t_push *swap, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(swap);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(swap);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(swap);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(swap);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(swap);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(swap);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(swap);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(swap);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(swap);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(swap);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(swap);
	else
		ft_error("Error\n");
}

void	ft_read(t_push *swap)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		ft_commands(swap, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main_p2(int argc, char **argv)
{
	t_push	swap;
	int		*a;
	int		*b;

	a = malloc(sizeof(int) * argc);
	b = ft_calloc(argc, sizeof(int));
	if (!a || !b)
		return (ft_error("Error allocated memory\n"));
	if (!ft_mistakes(argv, argc))
		return (ft_error("Error\n"));
	a = ft_convert(argc, argv);
	if (!a)
	{
		free(b);
		return (ft_error("Error\n"));
	}
	ft_init(a, b, argc, &swap);
	ft_read(&swap);
	if (ft_done(&swap) && b[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**new;
	int		i;

	i = argc - 1;
	new = &argv[1];
	if (argc == 1)
		return (ft_error("NO NUMBERS\n"));
	if (argc == 2)
	{
		new = ft_split(argv[1], ' ');
		if (!new)
			return (ft_error("Error allocated memory\n"));
		i = 0;
		while (new[i])
			i++;
	}
	if (main_p2(i, new))
		return (1);
	return (0);
}

int	get_next_line(char **line)
{
	int	buf[10000];
	int	byte;
	int	i;

	i = 0;
	if ((read(0, &buf[i], 0) < 0) || !(line))
		return (-1);
	byte = read(0, &buf[i], 1);
	while (byte > 0 && buf[i] != '\n')
		byte = read(0, &buf[++i], 1);
	buf[i] = '\0';
	if (byte != -1)
	{
		*line = malloc(sizeof(char) * i);
		if (*line)
		{
			i = -1;
			while (buf[++i])
				(*line)[i] = buf[i];
			(*line)[i] = '\0';
		}
	}
	if (byte > 0)
		return (1);
	return (byte);
}
