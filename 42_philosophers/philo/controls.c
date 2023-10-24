/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:17:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/24 03:25:55 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* bu fonksiyon eğer
	1) opsiyonel yemek sayısına ulaşılmışsa
	2) filozoflardan biri önceden ölmüşse (*is_dead kontrolü var cünkü) çıkar
	3) biri ölecekse (yemek yeme süresi dolarsa) 1 verir ve çıkar, çalışmaz. */
int ft_philo_check(t_philo *philo)
{
	/* eğer goal verilmemişse -1'dir default hali o yüzden bu kontrole asla
	girilmez. girilmişse ve yenilen yemek sayısı ona eşitlenirse döngüden çıkılır. */
	if (philo->eaten == philo->goal)
		return (1);
	/* 30 ve 37. satırlara ihtiyaç duyma sebebimiz şu:
	tek seferde sadece bir thread ölüm kontrolü yapsın
	aynı anda birden fazla thread herhangi bir filozof ölü mü
	kontrolü yaparsa bir thread okuma yaparken bir başka
	thread yazma yapabilir vs. burada int *is_dead shared data korunuyor. */
	pthread_mutex_lock(philo->lock);
	// eğer filo ölmüşse lockunu açıp çıkıyoruz
	if (*philo->is_dead)
	{
		pthread_mutex_unlock(philo->lock);
		return (1);
	}
	pthread_mutex_unlock(philo->lock);
	/* bir yandan sürekli şunu kontrol ediyor
	ölüm süresini geçerse öldü yazdırıyoruz. */
	if (ft_get_time() - philo->last_meal > philo->die_time)
	{
		print_philos_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

/* bu fonksiyonla eğer filozoflar bir işe başladıysa
o işin süresi dolana kadar bekletiyoruz. */
int waiting_philos(t_philo *philo, t_time wait_time)
{
	t_time time;

	/* o anki zamanı alıp time'a atiyoruz (1ocak70) */
	time = ft_get_time();
	while (ft_get_time() - time < wait_time)
	{
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
	1. elemani (tv_sec) saniye,
	2. elemani (tv_usec) microsaniye türündedir.
	aşağıdaki fonksiyonda bu 1. eleman bu structı gösteren pointerdır.
	bu pointer zamanı tutar. fonksiyon çağrıldığında
	ilk parametrenin point ettiği tv değişkenine zamanı
	yazar. pointer tipinde olması başka yerde de erişebilmek içindir.
	2. elemanda ise normalde greenwich'e göre geçen dakikayi vererek
	timezone belirtiliyor fakat çok nadir kullanılmakta. */
	gettimeofday(&tv, NULL);
	/* filo projesinde zaman birimi olarak milisaniye kullaniyoruz
	gettimeofday() ise micro saniye türünden yaziyor değişkenlerine
	micro saniye milisaniyeden cok cok kücüktür. bunu miliye cevirmek icin
	*1000 / 1000 yapiyoruz. */
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

/* data race nedir? data race iki thread aynı değişkene aynı anda ulaştıgında olur. bu threadlerden
en az bir tanesi okuma bir tanesi yazma yapiyor olmalıdır. bunu kodda kontrol etmek için
gcc -Wall ...'a -fsanitize=thread -g ekliyoruz. */
