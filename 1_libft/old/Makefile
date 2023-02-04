# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 04:01:36 by bkaramol          #+#    #+#              #
#    Updated: 2022/07/16 19:59:39 by bkaramol         ###   ########.fr        #
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

# extension aramaya vsc'de ext:s,c,o vs. yazarsan o uzantıyla ilgili
# paketler gelir
# değişkenleri yazarken $() içine yazıyoruz
# make ... demek ... komutunu çalıştır demek
# direkt make yazarsan ilk komutu çalıştırır

NAME = libft.a

# burada kaynak kodlarımızı listeliyoruz
SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

# bu komut ile .c uzantılıları .o uzantıya çeviriyoruz
# .o(bject) dosyası ne demek? makine dili ile C dili arasındaki levelde bir dosya
# türüdür. derleyici, ingilizce kelimelerle yazılan kodu 0-1 diline çevrilmeden önce
# bu dosyalara dönüştürür
OBJS			= $(SRCS:.c=.o)

# bonusları ekliyoruz
BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
					
BONUS_OBJS		= $(BONUS:.c=.o)

# aliaslar ekliyoruz
CC				= gcc

# make fclean dediğimizde rm -f komutunu kullanacak
RM				= rm -f

# otomatik olarak bu flaglerle derlemesini istiyoruz
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a


# iki noktadan önce yazdıkların kuraldır
# yanına yazdıkların kuralın geçerli olacağı şeydir
# altına indented yazdıkların da o kuralı gerçekleştirecek komutlardır
# kural: nesne
#	 komutlar
# komutlar sonucu kural oluşur, kuralın oluşabilmesi için nesneye ihtiyaç var
# makefile soldan sağa ve yukarıdan aşağıya çalışır. sıralamalar önemlidir


# all -> tüm kuralları çalıştıran kök kural
all:			$(NAME)

# başlarındaki $ onların değişken olduğunu söylüyor
# ar means archive. yoksa oluşturuyor.
# r --> replace the content in the archive
# c --> create a new archive
# s --> Write an object-file index into the archive
$(NAME):		$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# make clean: derleme sonrası oluşan ara dosyaları siler
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

# make fclean: derleme sonrası oluşan tüm dosyaları siler (fullclean)
fclean:			clean
				$(RM) $(NAME)

# make re: kütüphaneyi yeniden çalıştırır. önce fclean ile
# her şeyi siler sonra all ile yeniden yapar
re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# C clean kuralını çalıştırmak istesin. aynı adda bir başka klasör ya da dosya varsa
# ona gitmesin kural olan clean'i anlasın diye bunu yazıyoruz. mesela clean diye bi dosyan
# olsun. make clean dediğinde .o noktalarını silme işlemi değil clean'ı derleme işlemi yapacaktır
# eğer .phony'ye clean ismini dahil etmezsen. .gitignore gibi düşünebilirsin
.PHONY:			all clean fclean re bonus