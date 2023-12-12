#include <stdio.h>
#include <stdlib.h>

int ft_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return nb;
}

int *ft_rrange(int start, int end)
{
    int i = 0;
    int *arr;
    int len = ft_abs(start - end) + 1;

    arr = (int *)malloc(sizeof(int) * len);
    if (!arr)
        return 0;
    int x = 0;
    if (start >= end)
    {
        while (len)
        {
            arr[i] = end + x;
            x++;
            i++;
            len--;
        }
    }
    else if (start <= end)
    {
        while (len)
        {
            arr[i] = end - x;
            x++;
            i++;
            len--;
        }
    }
    else
    {
        arr[i] = start;
    }
    return arr;
}

int main()
{
    int *arr = ft_rrange(2, -2);
    int i = 0;
    while (i < 5)
    {
        printf("%d ", arr[i]);
        i++;
    }
}