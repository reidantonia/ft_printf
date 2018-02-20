#include "../includes/ft_printf.h"
#include <stdio.h>

int			main()
{
	char	*lel = "lelstr";
	char	*dog = "dogstr";
	char	*cat = "catstr";
	char	*hii = "hiistr";

	printf("ORIGINAL: HELLO %%s %%s %%s %%s %%s\n");
	ft_printf("ME: HELLO %s %s %s %s", hii, cat, dog, lel);
	printf("\n\nCOMPUTER: HELLO %s %s %s %s\n", hii, cat, dog, lel);
	return (0);
}
