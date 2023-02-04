/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:13:40 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:36:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s stringinin her bir karakterini f fonksiyonuna tâbi tutar ve 
// sonucu döndürür. f (a, b) fonksiyonunda a s'nin ilk  indisi, b de tâbi tutulacak indistir
// strmapi gibi bir buffer (yeni bir string) yaratıp onda işlem yapıp
// finalde de onu döndürmez, direkt string üzerinde işlem yapar
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	// uzuun string gelirse diye unsigned
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
