/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:31:07 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/14 13:34:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

template <typename T>
T min(T x, T y)
{
	if (x > y)
		return y;
	else if (x < y)
		return x;
	else
		return y;
}

template <typename T>
T max(T x, T y)
{
	if (x > y)
		return x;
	else if (x < y)
		return y;
	else
		return y;
}

template <typename T>
void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

/* why did I use variable reference for swap() and not for
min() and max()? because reference (&) allows you to directly
work on the object. without it, you always create distinct
copies of variables and any modification on them does not
take effect on the real objects but on the later-created ones.
in swap(), we want the changes be applied to the real objects,
not copies. since we used Template, it did not matter whether
or not we used references but normally, we'd prefer &.
for min and max there is no modification, just returning
greater/lesser number so we did not need a reference. */

#endif
