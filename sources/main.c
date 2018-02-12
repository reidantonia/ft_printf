#include "ft_printf.h"
#include <stdio.h>

int			main()
{
//	int		num;
	char	*lel = "lelstr";
	char	*dog = "dogstr";
	char	*cat = "catstr";
	char	*hii = "hiistr";

//	num = 2;
	ft_printf("ME:HELLO %s %s %s %s", hii, cat, dog, lel);
	//printf("\nCOMPUTER:HELLO %d\n", num);
	return (0);
}
