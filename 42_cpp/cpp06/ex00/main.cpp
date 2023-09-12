#include "Casting.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "You should enter ./convert [value]" << std::endl;
    }
    else
    {
        Casting::checkValue(av[1]);
        Casting::convert(av[1]);
    }
    return (0);
}