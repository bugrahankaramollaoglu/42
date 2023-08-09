/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:36:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/05/29 14:45:08 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* Execve fonksiyonu kısaca path'ini (yolunu) vermiş olduğunuz bir çalıştırılabilir dosyayı (programı) çalıştırma fonksiyonudur.
Eğer dosyayı çalıştırabilirse herhangi bir değer döndürmez. Ama eğer çalıştıramazsa '-1' değerini geri döndürür.
İlk parametresi verecek olduğumuz çalıştırılabilir dosyanın path'idir.
İkinci parametresi çalıştırılabilir dosyamızın eğer ki kullanıyorsa opsiyonudur. Örnek olarak 'ls' programının '-la' opsiyonu vb.
Üçüncü parametresi çevre değişkenleri (environment variables) ile alakalı. Çevre değişkeni kullanıyorsa
program o argümanları giriyorsunuz. */

int main()
{
	char *args[] = {"/bin/ls", "-lh", NULL};
	char *env[] = {NULL};

	if (execve("/bin/ls", args, env) == -1)
	{
		perror("execve");
		return 1; 
	}
}
