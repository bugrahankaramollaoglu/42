/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:04:44 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 14:18:05 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* kelimelerin sadece ilk harfini büyüğe çevir */

char	*ft_strcapitalize(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a])
	{
		// ilk harf küçükse büyük yap
		if (b == 0 && (str[a] >= 'a' && str[a] <= 'z'))
		{
			str[a] -= 32;
			b++;
		}

		// ilk harften sonraki harfler büyükse küçült
		else if (b > 0 && (str[a] >= 'A' && str[a] <= 'Z'))
			str[a] += 32;

		// a-z ve A-Z dışındakileri atla
		else if (str[a] < '0' || (str[a] > '9' && str[a] < 'A')
			|| (str[a] > 'Z' && str[a] < 'a') || (str[a] > 'z'))
			b = 0;
		else
			b++;
		a++;
	}
	return (str);
}
