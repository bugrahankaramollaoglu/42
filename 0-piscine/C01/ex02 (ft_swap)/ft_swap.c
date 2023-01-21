/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:28:36 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:24:43 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* swap is a technique that is often used
esp. when you want to change values of two variables.
for swap, you always need a temporary variable that'll hold
the value you'll change. why is that? this comes from the memory
management in C. in C, you always have to care about the memory location
you can't just say
int a, b;
a = b;
b = a;
because when you say a = b, b's value is assigned to a,
so a's value is lost. when you want to assign a's value
to b later on, it is already gone.
*/

#include <unistd.h>

void ft_swap(int *a, int *b)
{
    int temp;

    // you first assign a's value to temp so that it won't vanish
    temp = *a;
    *a = *b;

    // and then you assign temp's (actually a's) value to b
    *b = temp;
}

// you can also use
void ft_swap(int *a, int *b)
{
    *a ^= *b; // (1) a = a ^ b
    *b ^= *a; // (2) b = b ^ (a ^ b) = a
    *a ^= *b; // (3) a = (a ^ b) ^ a  = b  // a was set to a^b (1) and b became a (2)
}