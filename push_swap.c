#include "push_swap.h"

int	main_logic(int argc, char **argv)
{
	t_push	swap;
	int		*a;
	int		*b;

	b = ft_calloc(argc, sizeof(int));
	if (!b)
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
	if (!ft_done(&swap))
	{
		ft_algorithms(&swap);
		ft_finish(&swap);
	}
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = argc - 1;
	argv++;
	if (argc == 1)
		return (ft_error("NO NUMBERS\n"));
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		if (!argv)
			return (ft_error("Error allocated memory\n"));
		i = 0;
		while (argv[i])
			i++;
	}
	if (main_logic(i, argv))
		return (1);
	return (0);
}
