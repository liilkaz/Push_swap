#include "push_swap.h"

int	*ft_convert_part2(int *a, int quantity)
{
	int			i;
	int			j;
	long long	m;
	int			*a_dup;

	m = 0;
	a_dup = ft_calloc(quantity, sizeof(int));
	if (!a_dup)
		return (NULL);
	while (++m <= quantity)
	{
		i = 0;
		j = -1;
		while (a_dup[i] != 0)
			i++;
		while (++j < quantity)
		{
			if (a[i] > a[j] && i != j && a_dup[j] == 0)
				i = j;
			else if (a[i] == a[j] && i != j)
				return (NULL);
		}
		a_dup[i] = m;
	}
	return (a_dup);
}

int	*ft_convert(int quantity, char **argv)
{
	int			i;
	long long	m;
	int			*a_dup;
	int			*a;

	a = malloc(sizeof(int) * quantity);
	if (!a)
		return (NULL);
	i = -1;
	while (++i < quantity)
	{	
		m = ft_atoi(argv[i]);
		if (m > 2147483647 || m < -2147483648)
			return (NULL);
		a[i] = m;
	}
	a_dup = ft_convert_part2(a, quantity);
	free(a);
	if (!a_dup)
		return (NULL);
	return (a_dup);
}

int	ft_mistakes(char **argv, int quantity)
{
	int	i;
	int	j;

	i = 0;
	while (i < quantity)
	{	
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (j == 1 && (argv[i][j] == '\0'))
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
