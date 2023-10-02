#include <stdio.h>

int fun()
{
	int i = 5;
	i++;
	return i;
}

int fun2()
{
	static int i = 5;
	i++;
	return i;
}

int main()
{
	printf("%d\n", fun());	// 6
	printf("%d\n", fun());	// 6
	printf("%d\n", fun());	// 6
	printf("%d\n", fun2()); // 6
	printf("%d\n", fun2()); // 7
	printf("%d\n", fun2()); // 8
}
