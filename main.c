#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*buf[20];

	i = 0;
	i = read(0, buf, 10);
		printf("%d\n", i);
	return (0);
}
