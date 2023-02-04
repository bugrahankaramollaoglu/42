/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 06:45:13 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 09:31:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// her biri 'size' byte kadar yer tutan count adet nesne için yer ayırır
// ve ayrılan yere işaret eden bir pointer return eder. bu ayrılan yer de 
// sıfırlarla doldurulur. malloctan farkı budur.
void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	// a'ya yer ayırıyoruz
	a = malloc(count * size);
	if (!a)
		return (NULL);
	// bzero ile ayırdıgımız yere 0 yazdırıyoruz
	ft_bzero(a, count * size);
	return (a);
}

/* int	main()
{
	printf("ft_calloc =%p\n", ft_calloc(4, sizeof(char)));
	return (0);
}
 */