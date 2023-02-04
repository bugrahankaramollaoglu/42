/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:52:13 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 09:32:44 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s stringine baştan n kadar 0 (null) yazdırır (üzerine) ('0' değil \0)
// memset: s'ye baştan itibaren n kadar ortadaki parametreyi yazdırıyordu
// bzero("bugra", 3) --> 000ra

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* int main()
{
	unsigned char x[] = "asdasd";
	ft_bzero(x, 2);
	// en az 2 demen lazım ki null'ları atlayıp null olmayanları yazdırsın
	printf("%s\n", x + 2);
}
 */