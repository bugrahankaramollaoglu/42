// Passed Moulinette 2019.09.01

#include <stdio.h>

int count(int nb)
{
	int i = 0;
	while (nb)
	{
		if (nb % 10 == 2)
			i++;
		nb /= 10;
	}
	return i;
}

int fun(int nb) {
	int i = 1;
	int counter = 0;
	while (i <= nb) {
		counter += count(i);
		i++;
	}
	return counter;
}

int main()
{
	printf("%d\n", fun(25));

}
