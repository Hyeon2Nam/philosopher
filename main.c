/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:27 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/20 16:50:08 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_action(void *data)
{
	t_philo *philo;
	// pthread_t monitor;

	philo = (t_philo *)data;
	philo->info->start = get_time();
	philo->end_eating = get_time();
	// if (pthread_create(&monitor, NULL, monitor_die, (void *)philo) < 0)
	// 	return (0);
	// pthread_detach(monitor);
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		usleep(200);
	}
	return (0);
}

void *create_mutex(t_info *info)
{
	int i;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num);
	i = 0;
	while (++i < info->num)
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (0);
	pthread_mutex_init(&info->s_print, NULL);
	pthread_mutex_init(&info->action, NULL);
	return ((void *)1);
}

int create_thread(t_info *info)
{
	int i;

	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num);
	i = -1;
	while (++i < info->num)
	{
		info->philos[i].key = i + 1;
		info->philos[i].info = info;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = i + 1;
		if (i + 1 >= info->num)
			info->philos[i].right_fork = 0;
		if (pthread_create(&info->philos[i].thr, NULL, philo_action, (void *)&info->philos[i]) < 0)
			return (1);
		// if (pthread_mutex_init(&info->philos[i].die, NULL))
		// 	return (1);
	}
	i = -1;
	while (++i < info->num)
		pthread_join(info->philos[i].thr, NULL);
	// if (info->must_eat != -1)
	// 	if (pthread_create(&info->monitor, NULL, monitor_eat, (void *)info) < 0)
			// return (1);
	// pthread_join(info->monitor, NULL);
	return (0);
}

int main(int argc, char *args[])
{
	t_info info;
	int data[5];

	memset(data, -1, sizeof(int) * 5);
	if (argc > 6)
		return (-1);
	if (find_null(argc, args))
		return (-1);
	if (data_parse(argc, args, data))
		return (-1);
	info_init(&info, data);
	create_mutex(&info);
	create_thread(&info);
	// if (create_mutex(&info))
	// 	return (-1);
	// if (create_thread(&info))
	// 	return (-1);
	return (0);
}
