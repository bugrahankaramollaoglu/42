#include <stdarg.h>
#include <stdio.h>

int	sum(int numOfArg, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	va_start(ap, numOfArg);
	while (i < numOfArg)
	{
		sum += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (sum);
}

int	main(void)
{
	printf("%d\n", sum(5, 10, 20, 30, 40, 50));
}
