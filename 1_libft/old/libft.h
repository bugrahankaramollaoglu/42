/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:10 by bkaramol          #+#    #+#             */
/*   Updated: 2022/08/07 21:37:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if not defined, then define libft_h
// why _ rather than . IDK
#ifndef LIBFT_H
# define LIBFT_H

// kütüphanenin içine kütüphane atıyoruz böylece 
// libft.h'yi çağırdığımızda hepsi çağırılmış oluyor
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

/*
typedef: normalde veri tipine alias atamak için kullanılır.
1) (typedef eski_isim yeni_isim)
2) mesela --> typedef int abc; <--
3) artık --> abc myInt = 5; <-- diyebiliriz
struct deyimi ile beraber kullanıldığında
oluşturduğunuz yapıyı bir değişken türü olarak tanımlayıp
o yapının çoğaltılmasını sağlar. Bu yapıdan değişken tanımlamak
için tekrar struct deyiminin kullanılmasına gerek kalmaz.  
*/

// bir linked list tanımlıyoruz s_list isminde
// içine 2 tane değişken koyuyoruz
typedef struct s_list
{
	// veri tipsiz içerik atıyoruz
	void			*content;
	struct s_list	*next;
}	t_list;

// ascii türündeki str'yi integer'a çevirir
int			ft_atoi(const char *str);

// s'ye baştan n kadar null koyar
void		ft_bzero(void *s, size_t n);

// count adet size boyutunda nesne için yer ayırır ve ayırdıgı yeri nulla doldurur
void		*ft_calloc(size_t count, size_t size);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

// integer'ı char stringine çevirir
char		*ft_itoa(int n);

// s'de c'yi buldugu zaman c dahil s'nin kalanını döndürür (hafıza alanında)
void		*ft_memchr(const void *s, int c, size_t n);

// s1 ve s2'nin ilk n karakterini karşılaştırır, fark çıkarsa ascii farkını döndürür
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// src'den dst'e n kadar kopyalar. aynı hafıza alanındaysa it may though overlap
void		*ft_memcpy(void *dst, const void *src, size_t n);


// src'den dst'e len kadar kopyalar, aynı hafıza alanındaysa sondan kopyalar, sorun olmaz
void		*ft_memmove(void *dst, const void *src, size_t len);

// b'nin ilk len karakterine c yazar
void		*ft_memset(void *b, int c, size_t len);

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

int			ft_tolower(int c);
int			ft_toupper(int c);

// s'yi c'lerden ayırıp 2D bir arraye atar, onu döndürür
char		**ft_split(char const *s, char c);

// s'de c'yi bulursa c dahil kalanını döndürür 
char		*ft_strchr(const char *s, int c);

// s'de *sondan itibaren* c'yi arar bulursa c dahil kalanı döndürür
char		*ft_strrchr(const char *s, int c);

// s1'e önce yer ayırıp onu bir temp'e kopyalar, sonra tempi sonra döndürür
char		*ft_strdup(const char *s1);

// s'nin tüm elemanlarını (f) fonksiyonuna tâbi tutar ama bunu string üzerinde yapar
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// s'nin tüm elemanlarını (f) fonksiyonuna tâbi tutar ama bunu buffer üzerinden yapar
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// s1 ve s2 stringlerini uç uca ekler
char		*ft_strjoin(char const *s1, char const *s2);

// src'yi dest'in sonuna atar ama maksimum destSize kadar yer ayırır
size_t		ft_strlcat(char *dest, const char *src, size_t destSize);

// src'yi dest'e kopyalar ama maksimum destSize kadar yer ayırır
size_t		ft_strlcpy(char *dest, const char *src, size_t destSize);

// s'nin uzunluğunu hesaplar
size_t		ft_strlen(const char *s);

// s1 ve s2'nin ilk n karakterini karşılaştırır, fark bulursa farkı döndürür
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// haystack içinde ilk len karakterde needle arar, bulursa needle dahil kalanı döndürür
// str/memCHR'den farkı char değil string arar 
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

// s1'in başından ve sonundan set ve türevlerine denk gelirse siler
char		*ft_strtrim(char const *s1, const char *set);

// str'nin start. indisinden itibaren len karakter kadar yazdırır
char		*ft_substr(const char *str, unsigned int start, size_t len);

// listeye yeni eleman ekler
t_list		*ft_lstnew(void *content);

// listenin eleman sayısını verir
int			ft_lstsize(t_list *lst);

// listenin son elemanını verir
t_list		*ft_lstlast(t_list *lst);

// listeye baştan eleman ekler
void		ft_lstadd_front(t_list **alst, t_list *new);

// listeye sondan eleman ekler
void		ft_lstadd_back(t_list **alst, t_list *new);

// listeden bir eleman siler yerini de free() ile serbest bırakır
void		ft_lstdelone(t_list *lst, void (*del)(void*));

// listeden bir dizi eleman siler
void		ft_lstclear(t_list **lst, void (*del)(void*));

// listenin tüm elemanlarını (f) fonksiyonuna tâbi tutar ve döndürür
void		ft_lstiter(t_list *lst, void (*f)(void*));

// listenin tüm elemanlarını önce buffera atar, onu (f) fonksiyonuna tutar ve döndürür
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

// kütüphane kaynaklarının bittiğini gösterir
#endif
