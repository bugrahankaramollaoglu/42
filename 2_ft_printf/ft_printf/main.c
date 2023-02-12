#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = 50;
	int *aptr = &a;
	ft_printf("bugra\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 10);
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
}
