/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:27 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/16 17:44:39 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philo(t_info *info)
{
	pthread_mutex_t mutex;
	t_philo *philo;
	int i;
	int num = 3;
	int thr_id;

	pthread_mutex_init(&mutex, NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * num);
	i = -1;
	while (++i < num)
	{
		philo[i].mutex = &mutex;
		philo[i].key = i + 1;
		philo[i].info = info;
		thr_id = pthread_create(&philo[i].thr, NULL, ft_eat, (void *)&philo[i]);
		if (thr_id < 0)
		{
			printf("thread create error\n");
			return ;
		}
	}
	i = -1;
	while (++i < num)
		pthread_join(philo[i].thr, NULL);
	free(philo);
}

int main(int argc, char *args[])
{
	t_info info;
	int data[5];

	if (argc > 6)
		return (1);
	if (find_null(argc, args))
		return (1);
	if (data_parse(argc, args, data))
		return (1);
	printf("PASS\n");
	info_init(&info, data);
	create_philo(&info);
}
