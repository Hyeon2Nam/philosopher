/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:27 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/17 21:20:59 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_action(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	philo->info->start = get_time();
	// while (1)
	// {
		ft_fork(philo);
		ft_eat(philo);
		// ft_sleep(philo);
		// ft_think(philo);
		usleep(100);
	// }
	return (0);
}

void create_fork(t_info *info)
{
	int i;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num);
	i = 0;
	while (++i < info->num)
		if (pthread_mutex_init(&info->forks[i], NULL) < 0)
			return;
	pthread_mutex_init(&info->s_print, NULL);
	pthread_mutex_init(&info->action, NULL);
}

void create_philo(t_info *info)
{
	t_philo *philo;
	int thr_id;
	int i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num);
	i = -1;
	while (++i < info->num)
	{
		philo[i].key = i + 1;
		philo[i].info = info;
		philo[i].left_fork = i;
		philo[i].right_fork = i + 1;
		if (i + 1 >= info->num)
			philo[i].right_fork = 0;
		thr_id = pthread_create(&philo[i].thr, NULL, philo_action, (void *)&philo[i]);
		if (thr_id < 0)
			return;
	}
	i = -1;
	while (++i < info->num)
		pthread_join(philo[i].thr, NULL);
	free(philo);
	// pthread_create(&info->monitor, NULL, monitor_action, (void *)philo);
	// pthread_join(info->monitor, NULL);
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
	create_fork(&info);
	create_philo(&info);
	if (info.death)
		return (0);
	return (0);
}
