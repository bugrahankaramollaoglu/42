#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i])
    {
        result *= str_base;
        if (str[i] >= '0' && str[i] <= '9')
            result += str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            result += str[i] - 55;
        else if (str[i] >= 'a' && str[i] <= 'z')
            result += str[i] - 87;
        i++;
    }
    return (result * sign);
}

int main()
{
    char *str = "";
    printf("%d", ft_atoi_base(str, 16));
}