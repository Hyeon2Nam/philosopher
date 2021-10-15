/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:27 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/15 18:30:32 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
	pthread_mutex_t mutex;
	t_philo *philo;
	int i;
	int num = 3;
	int thr_id;

	pthread_mutex_init(&mutex, NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * num);
	i = 0;
	while (++i < num)
	{
		philo[i].mutex = &mutex;
		philo[i].key = i;
		thr_id = pthread_create(&philo[i].thr, NULL, eat, (void *)philo);
		if (thr_id < 0)
		{
			printf("thread create error\n");
			exit(1);
		}
	}

	// pthread_create(&thr1, NULL, eat, (void *)"thread 1");
	// pthread_create(&thr2, NULL, eat, (void *)"thread 2");
	// thr_id = pthread_create(&thr, NULL, eat, (void *)"thread 1");
	// thr_id = pthread_create(&thr, NULL, eat, (void *)"thread 2");
	// if (thr_id < 0)
	// {
	// 	printf("thread create error\n");
	// 	exit(1);
	// }
	i = 0;
	while (++i < num)
		pthread_join(&philo[i].thr, NULL);
	i = 0;
	while (++i < num)
		free(philo);
	exit(0);
}
