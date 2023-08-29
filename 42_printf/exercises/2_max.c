#include <stdarg.h>
#include <stdio.h>

int max(int numOfArgs, ...)
{
	va_list ap;
	va_start(ap, numOfArgs);
	int i = 1;
	int max = va_arg(ap, int);
	int tmp;
	while (i < numOfArgs)
	{
		tmp = va_arg(ap, int);
		if (tmp > max)
			max = tmp;
		i++;
	}
	va_end(ap);
	return max;
}

int main()
{
	printf("%d\n", max(4, 10, 235, 63, 93));
}
