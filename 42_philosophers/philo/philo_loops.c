/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:09:19 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/06 12:30:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* filozofların döngülerini çalıştıran fonksiyon */
void *loops_for_philos(void *argument)
{
	t_philo *philo;

	philo = (t_philo *)argument;
	/* filozof sayisi 1 ise ve koşullara da uyuyosa (kimse ölmemişse önceden vs.) direkt çatal aldırıp öldürüyoruz. */
	if (philo->philo_num == 1)
	{
		/* eğer sol çatalı kitleyemiyosa null döndürüyoruz.
		pthread_mutex_lock() fonksiyonu hata yoksa 0 varsa sayı döndürür.
		bu sayı hatanın tipine göre degisebilir:

		EBUSY: mutex başka mutex tarafından zaten kitli
		EINVAL: mutex ilklendirilmedi ya da geçersiz
		EAGAIN: max recursive lock sayısı aşıldı (o mutex için)
		EDEADLK: mutex zaten kitlendi, eğer kitlemeye çalışırsan deadlock oluşur. */
		if (pthread_mutex_lock(philo->left_fork_mutex) != 0)
			return (NULL);
		print_philos_status(philo, " has taken a fork", 0);
		/* bir yandan da sürekli işlemler devam etmeli mi diye kontrol ediyoruz. bu
		fonksiyon eğer biri ölmüşse/hedefe ulaşılmışsa vs. 1 yoksa döndürür.
		yani bütün program ft_philo_check 1 döndürmediği sürece çalışır. */
		while (!ft_philo_check(philo))
		{
		}
		// sadece 1 filo oldugundan onun catalını kitleyip actık
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	/* diğer türlü filo_check hata verip çıkana kadar filozoflara
		1) yediriyoruz
		2) uyutuyoruz
		3) düşündürüyoruz */
	while (1)
	{
		/* eğer kontrollerden geçemiyosa break ile bu 3 eylemin art arda sürdürme sürecinden
		break ile çıkıyoruz */
		if (ft_philo_check(philo))
			break;
		/* yemek yiyorlar */
		eat_time_philos(philo);
		/* uyuyorlar */
		sleep_time_philos(philo);
		/* eğer bunlar olana kadar ölmemişlerse uyuyorlar */
		if (!ft_philo_check(philo))
			print_philos_status(philo, "is thinking", 0);
	}
	return (NULL);
}

/* ekrana yazı yazdıran fonksiyon */
void print_philos_status(t_philo *philo, char *status, int kill)
{
	/* eğer bunu koymazsak filoyu kitlememiş oluruz o zaman da ölse bile işlemlere devam eder.
	aşağıki satıra geçmez. bu yüzden birisi oldugu zaman digerleri devam eder. bir ölümden
	tüm threadler sorumlu. */
	pthread_mutex_lock(philo->lock);
	/* eğer filozof ölmemişse kontrol ediyoruz */
	if (!*philo->is_dead)
	{
		/* informatif tüm satırları yazdırırken kullanılan printf. status
		burada eat, die, sleep ve think olabilir. filozof_id'leri ekrana yazdırırken
		1'den başladığı için +1 dedik. terminale sırasıyla sunlar yazdırılır:
		geçen_milisaniye [filozof_id] -> yapılan_iş */
		printf("%llu [%d] -> %s\n", (ft_get_time() - philo->start_time),
			   philo->id + 1, status);
		/* eğer kill 1 olarak verilmişse dead_flag'i düzenliyoruz. */
		if (kill)
			*philo->is_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

/* filozofları yemek yedirmek icin bu fonksiyonu kullanıyoruz */
void eat_time_philos(t_philo *philo)
{
	/* solundaki sağındaki çatalları alıyor ve kitliyor. */
	pthread_mutex_lock(philo->left_fork_mutex);
	print_philos_status(philo, "has taken a fork ", 0);
	pthread_mutex_lock(philo->right_fork_mutex);
	print_philos_status(philo, "has taken a fork", 0);
	/* bu fonksiyon hemen her yerde calısıyor */
	if (ft_philo_check(philo))
		return;
	print_philos_status(philo, "is eating", 0);
	pthread_mutex_lock(philo->lock);
	philo->last_meal = ft_get_time();
	philo->eaten++;
	pthread_mutex_unlock(philo->lock);
	// yemek süresi kadar kendi threadini bekleten fonksiyon
	waiting_philos(philo, philo->eat_time);
}

void sleep_time_philos(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_check(philo))
		return;
	print_philos_status(philo, "is sleeping", 0);
	/* waiting_philos() fonksiyonu sleep_time dolana kadar sleep() atiyor yani
	kendi threadini bekletiyor ki zaman geçsin. bunu nası yapiyor?
	bu fonksiyon bitene kadar sleep_time_philos()
	fonksiyonundan çıkamayacağı için bekletmiş oluyoruz. */
	waiting_philos(philo, philo->sleep_time);
}
