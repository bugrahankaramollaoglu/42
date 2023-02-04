libft'de replikalarını yazdığımız bu fonksiyonlar birçok kaynağın C öğretirken yaptırdığı egzersizler. 
genellikle stdio.h'taki built-in fonksiyonları tekrar ediyoruz.
submit etmen gereken seyler
  - içinde tüm fonksiyonların prototiplerinin, bonuslar içinse struct yapısının oldugu, libft library'sini
  tanımladıgın, standart kütüphaneler ekledigin, sonuna #endif koydugun bir libft.h dosyası
  - tüm dosyalarını derleyecek bir Makefile dosyası (makefile'ı sıfırdan yazmaya calismak gereksiz, bir yerden alıp satırların anlamları calısılabilir. çünkü çok şablon bir şey.). flagleri vs. ekleyerek özelleştiriyosun makefile'ı.
  - ve .c uzantılı fonksiyonların.

- libft projesini kendin yazmak istiyosan en iyi şey halihazırda havuzda önceden yazdığın kodları kullanmak. 
  çünkü zaten libft'nin çoğu havuz'da var. kalanı da manual okuyarak, farklı referans kitaplarına bakarak (deitel, how to C ya da necati ergin c ders notları güzel bir örnek) yazılabilir.

- 



## **libft fonksiyonları ne işe yarıyor?**

 ft_atoi : ascii türündeki str'yi integer'a çevirir
> int ft_atoi(const char *str);

 ft_bzero : s'ye baştan n kadar null koyar
>void ft_bzero(>void *s, size_t n);

 ft_calloc : count adet size boyutunda nesne için yer ayırır ve ayırdıgı yeri nulla doldurur
>void *ft_calloc(size_t count, size_t size);

 ft_isalnum : parametresi harf ya da rakamsa 1, değilse 0 döndürür 
> int ft_isalnum(int c);

 ft_isalpha : parametresi harf ise 1, değilse 0 döndürür
> int ft_isalpha(int c);

 ft_isascii . parametresi ascii ise 1, değilse 0 döndürür
> int ft_isascii(int c);

 ft_isdigit : parametresi rakamsa 1, değilse 0 döndürür 
> int ft_isdigit(int c);

 ft_isprint : parametresi printable (0-31 aralığında) ise 1, değilse 0 döndürür
> int ft_isprint(int c);

 ft_itoa : integer'ı char stringe çevirir
> char *ft_itoa(int n);

 ft_memchr : s'de c'yi buldugu zaman c dahil s'nin kalanını döndürür (hafıza alanında)
> void *ft_memchr(const void *s, int c, size_t n);

 ft_memcmp : s1 ve s2'nin ilk n karakterini karşılaştırır, fark çıkarsa ascii farkını döndürür
> int ft_memcmp(const void *s1, const void *s2, size_t n);

 ft_memcpy : src'den dst'e n kadar kopyalar. aynı hafıza alanındaysa it may though overlap
>void *ft_memcpy(void *dst, const void *src, int n);

 ft_memmove : src'den dst'e len kadar kopyalar, aynı hafıza alanındaysa sondan kopyalar, sorun olmaz
>void *ft_memmove(void *dst, const void *src, size_t len);

 ft_memset : b'nin ilk len karakterine c yazar
>void *ft_memset(void *b, int c, size_t len);

 ft_putchar_fd : dosyaya karakter yazdırır
> void ft_putchar_fd(char c, int fd);

 ft_putendl_fd : dosyaya string yazdırır, sonuna \n koyar
>void ft_putendl_fd(char const *s, int fd);

 ft_putnbr_fd : dosyaya sayı yazdırır
>void ft_putnbr_fd(int n, int fd);

 ft_putstr_fd : dosyaya string yazdırır
>void ft_putstr_fd(char *s, int fd);

 ft_tolower : parametresi büyükse küçük yapar
>int ft_tolower(int c);

 ft_toupper : parametresi küçükse büyük yapar
>int ft_toupper(int c);

  ft_split : s'yi c'lerden ayırıp 2D bir arraye atar, onu döndürür
> char **ft_split(char const *s, char c);

 ft_strchr : s'de c'yi bulursa c dahil kalanını döndürür
> char *ft_strchr(const char *s, int c);

 ft_strrchr : s'de *sondan itibaren* c'yi arar bulursa c dahil kalanı döndürür
> char *ft_strrchr(const char *s, int c);

 ft_strdup : s1'e önce yer ayırıp onu bir temp'e kopyalar, sonra tempi sonra döndürür
> char *ft_strdup(const char *s1);

 ft_striteri : s'nin tüm elemanlarını (f) fonksiyonuna tâbi tutar ama bunu string üzerinde yapar
> void ft_striteri(char *s, void (*f)(unsigned int, char *));

 ft_strmapi : s'nin tüm elemanlarını (f) fonksiyonuna tâbi tutar ama bunu buffer üzerinden yapar
> char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

 ft_strjoin : s1 ve s2 stringlerini uç uca ekler
> char *ft_strjoin(char const *s1, char const *s2);

 ft_strlcat : src'yi dest'in sonuna atar ama destSize-1 kadar yer ayırır, null'a kesinlikle 1 byte bırakır
> size_t ft_strlcat(char *dest, const char *src, size_t destSize);

 ft_strlcpy : src'yi dest'e kopyalar ama maksimum destSize kadar yer ayırır
> size_t ft_strlcpy(char *dest, const char *src, size_t destSize);

 ft_strlen : s'nin uzunluğunu hesaplar
> size_t ft_strlen(const char *s);

 ft_strncmp : s1 ve s2'nin ilk n karakterini karşılaştırır, fark bulursa farkı döndürür
> int ft_strncmp(const char *s1, const char *s2, size_t n);

 ft_strnstr : haystack içinde ilk len karakterde needle arar, bulursa needle dahil kalanı döndürür. strchr'den farkı char değil string arar.
> char *ft_strnstr(const char *haystack, const char *needle, size_t len);

 ft_strtrim : s1'in başından ve sonundan set ve türevlerine denk gelirse siler
> char *ft_strtrim(char const *s1, const char *set);

 ft_substr : str'nin start. indisinden itibaren len karakter kadar yazdırır
> char *ft_substr(const char *str, unsigned int start, size_t len);

 ft_lstnew : listeye yeni eleman ekler
> t_list *ft_lstnew(>void *content);

 ft_lstsize : listenin eleman sayısını verir
> int ft_lstsize(t_list *lst);

 ft_lstlast : listenin son elemanını verir
> t_list *ft_lstlast(t_list *lst);

 ft_lstadd_front : listeye baştan eleman ekler
> void ft_lstadd_front(t_list **alst, t_list *new);

 ft_lstadd_back :  listeye sondan eleman ekler
> void ft_lstadd_back(t_list **alst, t_list *new);

 ft_lstdelone : listeden bir eleman siler yerini de free() ile serbest bırakır
>void ft_lstdelone(t_list *lst, void (*del)(void *));

 ft_lstclear : listeden bir dizi eleman siler
>void ft_lstclear(t_list **lst, void (*del)(void *));

 ft_lstiter :  listenin tüm elemanlarını (f) fonksiyonuna tâbi tutar ve döndürür
>void ft_lstiter(t_list *lst, void (*f)(void *));

 listenin tüm elemanlarını önce buffera atar, onu (f) fonksiyonuna tutar ve döndürür
> t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));