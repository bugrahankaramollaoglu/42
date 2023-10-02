/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:36:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 14:20:41 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* Execve fonksiyonu kısaca path'ini (yolunu) vermiş olduğunuz bir
çalıştırılabilir dosyayı (programı) çalıştırma fonksiyonudur.

execve(const char*fileName, const char*av[], const char*env[]);

hata durumunda -1 döndürür, başarı durumunda direkt çalıştırır, bişey döndürmez */

int main()
{
	char *args[] = {"/bin/ls", "-lh", NULL};
	char *env[] = {NULL};

	execve("/bin/ls", args, env);
}
