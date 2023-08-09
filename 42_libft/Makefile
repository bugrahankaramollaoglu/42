# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:16:20 by bkaramol          #+#    #+#              #
#    Updated: 2023/06/24 22:18:55 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	makefile tekniği çok sayıda kodu kolayca derleyip debug etmeye yarar.
# 	yani tek tek gcc *.c yazmamıza gerek kalmıyor. gcc'nin çalışma mantığı
# 		1) preprocessing (standart çıktı) [gcc -E]
# 			*	yorumları siler
# 			*	makroları açar
# 			*	.h uzantılı kütüphaneleri import eder
# 				bunun için direkt olarak kütüphaneyi kopyalar
# 				koda yapıştırıp çalıştırır
# 		2) compiling (derleme) [gcc -S]
# 			*	assembly koduna çevirir
# 			*	böylelikle asd.s (assembly uzantısı) oluşur
# 		3) assembly (bir araya getirme) [gcc -c]
# 			*	assembly kodu makina diline (0-1) çevrilir
# 			*	böylece .o uzantılı object dosyaları oluşur
# 				bu dosyalar makine diline en yakın aşamadır
# 		4) linking (bağlama)
# 			*	nesne kodları çalıştırılabilir bir dosyaya linklenir
# 			*	bu işlemin sonucunda nihai çalıştırılabilir dosya
# 				elde edilir (.exe ya da .out veya uzantısız)

# renk kodları
GREEN=\033[0;32m
RESET=\033[0m

# makefile çalıştıktan sonra üretilecek output dosyası
NAME    = libft.a

# derlenecek dosyalar
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \

BONUSES	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		  ft_lstdelone.c ft_lstiteri.c ft_lstlast.c \
		  ft_lstmap.c ft_lstnew.c ft_lstsize.c

# dönüştürülecek .o dosyaları
OBJECTS = ${SOURCES:.c=.o}

BONUS_OBJECTS = ${BONUSES:.c=.o}

# cc ile derliyoruz
# cc aslında bir OS'deki default C derleyicisine atanan
# bir alias'tır. gcc ise GNU project'in derleyicisidir.
# karıştırılsa da GNU Unix değildir.
CC = cc

# flagler
CFLAGS = -Wall -Werror -Wextra

# sadece make dediğimizde her zaman ilk komut çalışır
# iki noktadan önce yazdıkların kuraldır
# yanına yazdıkların kuralın geçerli olacağı şeydir
# altına indented yazdıkların da o kuralı gerçekleştirecek komutlardır
# kural: nesne
#	 komutlar
# komutlar sonucu kural oluşur, kuralın oluşabilmesi için nesneye ihtiyaç var
# makefile soldan sağa ve yukarıdan aşağıya çalışır. sıralamalar önemlidir
# all -> tüm kuralları çalıştıran kök kural
# burada neden direkt ar rcs komutunu all'ın altında yazmadık?
# çünkü biz en sonda $name isimli bir dosya oluşsun istiyoruz ki relink olmasın
# yani her make dendiginde makefile tekrar tekrar çalışmasın. bunun için ana kuralın
# çıktısı isminde bir dosya olmalı, bunu da all'ı dolaylı yazarak sağlıyoruz
all: ${NAME}

# name de aynı şekilde çalışmadan evvel yanındakileri built ediyor
# makefile'da buna dependencies deniyor. yani OBJ ve BONUS_OBJ'ler
# işlendikten sonra alttaki kendi komutlarını işlemeye başlıyor.
# ar komutu burada statik kütüphane arşivi oluşturmada kullanılır
# rcs ise onun flagleridir. (r) dosyaları arşive eklemeye yariyor, replace
# (c) dosya arşivde yoksa yaratmaya yariyor, create
# (s) indexlemeye yariyor
# başına @ koydugun komutlar ise terminale yazdırılmaz
${NAME}: ${OBJECTS} ${BONUS_OBJECTS}
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

# make clean dediğimizde obje dosyalarını (.o) siler
clean:
	@rm -rf ${OBJECTS} ${BONUS_OBJECTS}
	@echo "$(GREEN)[clean]$(RESET) has been used."

# libft.a + outputları siler
fclean: clean
	@rm -rf ${NAME}
	@echo "$(GREEN)fclean$(RESET) has been used."

# her şeyi silip yeniden makeler
re: fclean all

# bonusları özel derlemekte kullanılır
bonus: ${OBJECTS} ${BONUS_OBJECTS}
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

# burada komut olanlar ile dosya olanlar karıştırılmasın diye .phony ekledik.
# mesela clean diye bi dosyan olsun. make clean dediğinde .o noktalarını
# silme işlemi değil dosya olan clean'ı derleme işlemi yapacaktır eğer .phony'ye clean ismini
# dahil etmezsen. phony anahtar kelimedir makefile için.
.PHONY:			all clean fclean re bonus
