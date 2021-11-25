/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:27 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/25 20:00:07 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action(void *data)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)data;
	info = philo->info;
	if (!(philo->key % 2))
		usleep(200);
	while (!(info->die))
	{
		ft_eat(philo);
		if ((info->must_eat > 0 && monitor_eat(info, philo)) || info->die)
			break ;
		ft_sleep(philo);
		ft_think(philo);
		usleep(200);
	}
	return (0);
}

int	create_mutex(t_info *info)
{
	int	i;

	info->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * info->num);
	if (!info->forks)
		return (1);
	i = 0;
	while (i < info->num)
		if (pthread_mutex_init(&info->forks[i++], NULL))
			return (1);
	if (pthread_mutex_init(&info->s_print, NULL))
		return (1);
	if (pthread_mutex_init(&info->eat_check, NULL))
		return (1);
	return (0);
}

int	philo_init(t_info *info)
{
	int	i;

	i = -1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num);
	if (!info->philos)
		return (1);
	while (++i < info->num)
	{
		info->philos[i].key = i + 1;
		info->philos[i].is_eat = 0;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num;
		info->philos[i].eat_count = 0;
		info->philos[i].info = info;
	}
	return (0);
}

int	create_thread(t_info *info)
{
	t_philo	*philo;
	int		i;

	info->start = get_time();
	if (info->num == 1)
	{
		ft_usleep(info->die_time);
		print_status(info, 1, "died\n");
		return (0);
	}
	i = -1;
	philo = info->philos;
	while (++i < info->num)
	{
		info->philos[i].end_eat = get_time();
		if (pthread_create(&philo[i].thr, NULL,
				philo_action, &philo[i]) != 0)
			return (1);
	}
	monitor_die(info, info->philos);
	i = -1;
	while (++i < info->num)
		pthread_join(philo[i].thr, NULL);
	return (0);
}

int	main(int argc, char *args[])
{
	t_info	info;
	int		data[5];

	memset(data, 0, sizeof(int) * 5);
	if (argc > 6)
		return (-1);
	if (find_null(argc, args))
		return (-1);
	if (data_parse(argc, args, data))
		return (-1);
	if (info_init(&info, data))
		return (-1);
	if (create_mutex(&info))
		reset(&info);
	if (create_thread(&info))
		reset(&info);
	reset(&info);
	return (0);
}
