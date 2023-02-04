/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:08:16 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/29 18:11:36 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  split() fonksiyonu verilen char stringi c'lerden ayırarak bir arraye atar.
    bunu yaparken malloc() kullanır. */

// c'lerden ayrılmış str'deki kelime sayısını hesaplayan fonksiyon
static int ft_word_count(char const *str, char c)
{
    int index;

    // bulunan kelime sayacı
    int word_counter;

    index = 0;

    word_counter = 0;

    // str bitene kadar
    while (str[index])
    {
        // eğer indeks c ise bir atla (ki asıl kelimeye gelelim)
        // remember that c's are not included
        if (str[index] == c)
            index++;
        // eğer c değilse
        else
        {
            // kelime sayısını bir arttır
            word_counter++;
            // fakat aynı zamanda eğer
            // string sonu ve c değilse indisi buldugun kelimenin sonuna
            // gelene kadar arttırmayı unutma
            while (str[index] && str[index] != c)
                index++;
        }
    }
    return (word_counter);
}

// bu fonksiyon kelime yazdırmaya (doldurmaya) yarıyor
// i burada word_len ile aynı. kelimenin uzunluguna esitleniyor
// i - word_len ve word_len-- diyerek s'nin 0. 1. 2. vs. indisini atıyoruz word[0, 1, 2]'ye
static char *ft_putword(char *word, char const *s, int i, int word_len)
{
    // j burada sayacımız
    int j;

    j = 0;

    // kelime uzunluğu bitene kadar
    while (word_len > 0)
    {
        // önce s'nin i - word_len yani 0. indisini word[0]'a
        // atıyor. sonra 1. indisini word[1]'e sonra 2. indisin
        // word[2]'ye diye gidiyor
        word[j] = s[i - word_len];
        j++;

        // burada word_len verilmemis diye sasirma cünkü bu
        // fonksiyonu tekrar kullandıgımızda 4. parametre olarak gelecek
        word_len--;
    }
    // sonunda word'ün sonuna null koyuyor ki C stringi olsun
    word[j] = '\0';
    // ve döndürüyor
    return (word);
}

// spliti kelimelere ayırma ve malloc işlemi yapar
// new_str: splitted kelimelerin atılacağı string
static char **ft_split_words(char const *s, char c,
                             char **new_str, int num_words)
{
    int i;
    int word;
    int word_len;

    i = 0;
    word = 0;
    word_len = 0;

    // num_words kadar islem yapiyoruz
    // num_words daha sonra parametre olarak verilecek
    while (word < num_words)
    {
        // c'ye denk gelirse atla ki gercek kelimeye gelelim
        while (s[i] && s[i] == c)
            i++;
        // değilse de bir sonraki c'ye kadar atla ve
        // kelime uzunlugunu bir arttır
        while (s[i] && s[i] != c)
        {
            // böylelikle o anki dolduracağı kelimenin uzunlugunu bulmuş oluyor
            word_len++;
            i++;
        }
        // new_str'nin önce 0. indisine kelime uzunlugu + 1 (null) kadar
        // yer ayırıyoruz. daha sonra 1. 2. 3. indisine ayıracağız
        // bunu böyle yapma sebebimiz her kelimenin farklı uzunlukta olması
        new_str[word] = (char *)malloc(sizeof(char) * (word_len + 1));

        // if malloc fails return null
        if (!new_str)
            return (NULL);

        // daha sonra yer ayırdığımız alana putword() ile kelime dolduruyoruz
        // 1. parametre new_str'nin 0. kelimesi
        // 2. parametre stringimiz s
        // 3. parametre i sayacı
        // 4. parametre de word_len yani kelime uzunlugu
        // özetle s'yi kelimelere ayırdıktan ve kelimelerin sayısını
        // bulduktan sonra iki tane sayaç yardımıyla yazdırma işlemi yapıyor
        ft_putword(new_str[word], s, i, word_len);
        // finalde word_len'i 0 a eşitliyoruz ki her kelime icin
        // yeni uzunluk atayıp doldursun, sıfırlansın yani her seferinde
        word_len = 0;
        word++;
    }
    // her kelimenin sonuna null koyuyoruz
    new_str[word] = NULL;
    return (new_str);
}

// asıl fonksiyonumuz
char **ft_split(char const *s, char c)
{
    // *s'nin split edilmiş halini tutacak 2-D string
    char **final_str;

    // *s'yi c'lerden ayırdıgımızda gelen kelime sayisi
    size_t num_words;

    // eğer s boşsa null döndür
    if (!s)
        return (0);

    // daha evvel yazdıgımız fonksiyonla kelime sayisini hesapla
    num_words = ft_word_count(s, c);

    // final string için yer ayır
    final_str = (char **)malloc(sizeof(char *) * (num_words + 1));

    // if fails, return null
    if (!final_str)
        return (0);

    // sonra sadece fonksiyonu çağır
    ft_split_words(s, c, final_str, num_words);
    return (final_str);
}

/* int main()
{
    char test[] = "bugra++kara+molla+++++oglu";
    char **arr = ft_split(test, '+');
    int i = 0;
    while (arr[i])
    {
        printf("[%s]\n", arr[i]);
        ++i;
    }
} */

/* a much, much better split

#include "libft.h"

static int	wordcounter(const char *s, char c)
{
    int	i;

    i = 0;
    while (*s)
    {
        while (*s == c && *s)
            s++;
        if (*s == '\0')
            return (i);
        while (*s != c && *s)
            s++;
        i++;
    }
    return (i);
}

static int	charcounter(const char *s, char c)
{
    int	i;

    i = 0;
    while (*s && *s != c)
    {
        i++;
        s++;
    }
    return (i);
}

char	**ft_split(char const *s, char c)
{
    char	**ret;
    int		retindex;

    if (!s)
        return (0);
    retindex = 0;
    ret = malloc(sizeof(char *) * wordcounter(s, c) + 1);
    if (!ret)
        return (0);
    while (*s)
    {
        while (*s == c && *s)
            s++;
        if (*s == '\0')
            break ;
        ret[retindex] = ft_substr(s, 0, charcounter(s, c));
        retindex++;
        s = s + charcounter(s, c);
    }
    ret[retindex] = NULL;
    return (ret);
} 

int main()
{
    char test[] = "bugra++kara+molla+++++oglu";
    char **arr = ft_split(test, '+');
    int i = 0;
    while (arr[i])
    {
        printf("[%s]\n", arr[i]);
        ++i;
    }
} */

