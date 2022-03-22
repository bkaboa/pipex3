#include "../Includes/pipex.h"

int	main(void)
{
	char	*s = "1 2 3 4 5 6";
	int		i;
	char	**split;

	i = 0;
	split = ft_split(s, ' ');
	while (split[i])
		printf("%s", split[i++]);
	return (0);
}
