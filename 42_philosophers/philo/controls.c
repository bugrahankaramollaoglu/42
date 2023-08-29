/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/11 00:34:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* bu fonksiyon eğer
	1) opsiyonel yemek sayısına ulasılmısa çıkar
	2) filozoflardan biri önceden ölmüşse (*is_dead kontrolü var cünkü) çıkar
	3) biri ölecekse (yemek yeme süresi dolarsa) 1 verir ve çıkar. */
int ft_philo_check(t_philo *philo)
{
	/* eğer goal verilmemişse -1'dir default hali o yüzden bu kontrole asla
	girilmez. girilmişse ve yenilen yemek sayısı ona eşitlenirse döngüden çıkılır. */
	if (philo->eaten == philo->goal)
		return (1);
	pthread_mutex_lock(philo->lock);
	if (*philo->is_dead)
	{
		pthread_mutex_unlock(philo->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->lock);
	/* ölüm süresini geçerse öldü yazdırıyoruz. */
	if (ft_get_time() - philo->last_meal > philo->die_time)
	{
		/* filozofların o anki durumlarını bastıracak fonksiyona gönderen fonksiyon */
		print_philos_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

/* bir filozof yemek yedikten sonra diğerini beklemesini sağlayan fonksiyon.
daha sonra kullanırken birinci parametreye filoyu, ikinciye
her filonun yemek yeme ve uyuma süresini verecek. kalan zamanda (düsünme) süre
belli olmadıgı icin onda kullanmıyoruz. */
int waiting_philos(t_philo *philo, t_time wait_time)
{
	t_time time;

	/* o anki zamanı alıp time'a atiyoruz (1ocak70) */
	time = ft_get_time();
	while (ft_get_time() - time < wait_time)
	{
		/* bu arada da sürekli ölüm kontrolü yapiyoruz. */
		if (ft_philo_check(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

t_time ft_get_time(void)
{
	struct timeval tv;
	unsigned long long time;

	/* bu fonksiyon time.h'da bulunur. genelde iki kod blogunun calısma
	zamanı arasındaki süreyi hesaplamak için kullanılır.
	struct timeval türünde o anki zamani döndürür. bu timeval isimli structın
	1. parametresi saniye,
	2. parametresi microsaniye türündedir.
	aşağıdaki fonksiyonda bu 1. parametre bu structı gösteren pointerdır.
	bu pointer zamanı tutar. fonksiyon çağrıldığında
	ilk parametrenin point ettiği tv değişkenine zamanı
	yazar. pointer tipinde olması başka yerde de erişebilmek içindir.
	2. parametrede ise normalde greenwich'e göre geçen dakikayi vererek
	timezone belirtiliyor fakat çok nadir kullanılmakta. */
	gettimeofday(&tv, NULL);
	/* 	micro saniye milisaniyeden cok cok kücüktür. bunu miliye cevirmek icin
	*1000 /1000 yapiyoruz. tv_sec saniye türünden,
	tv_usec mikrosaniye türünden. gettimeofday’i kullandığımızda görüyoruz ki:
	mikrosaniye çok hızlı değişirken saniye ise yavaş değişiyor
	(kod satırları arasında yavaş değişiyor normal düşünme). ikisinin ortasında
	ortalama bir değişime sahip değişkene ihtiyacımız var
	bu yüzden saniyeyi 1000’ le çarpıp mikrosaniyeyi 1000’e bölüp toplayıp
	milisaniye cinsinden karşılığını buluyoruz. kısaca saniye/mikrosaniye ortalamasını
	almak için diyebiliriz. böylelikle filozoflardaki
	değişimi kontrol etmemiz kolaylaşıyor. ayrıca time_to_die değerlerini
	kullanıcı bize milisaniye cinsinden veriyor her türlü çevirmek lazım*/
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

/* data race nedir? data race iki thread aynı değişkene aynı anda ulaştıgında olur. bu threadlerden
en az bir tanesi okuma bir tanesi yazma yapiyor olmalıdır. bunu kodda kontrol etmek için
gcc -Wall ...'a -fsanitize=thread -g ekliyoruz. */
