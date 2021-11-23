/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:20:25 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/21 19:58:19 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_philo *philo)
{
	t_info *info;

	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->left_fork]);
	print_status(info, philo->key, "has taken a fork\n");
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	print_status(info, philo->key, "has taken a fork\n");
	pthread_mutex_lock(&info->eat_check);
	print_status(info, philo->key, "is eating\n");
	philo->end_eat = get_time();
	pthread_mutex_unlock(&philo->info->eat_check);
	ft_usleep((philo->info->eat_time));
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void ft_sleep(t_philo *philo)
{
	t_info *info;

	info = philo->info;
	print_status(info, philo->key, "is sleeping\n");
	ft_usleep(philo->info->sleep_time);
}

void ft_think(t_philo *philo)
{
	t_info *info;

	info = philo->info;
	print_status(info, philo->key, "is thinking\n");
}

void monitor(t_info *info, t_philo *philo)
{
	int i;

	while (!(info->all_ate))
	{
		i = -1;
		while (++i < info->num && !(info->die))
		{
			pthread_mutex_lock(&info->eat_check);
			if ((philo[i].end_eat - get_time()) > info->die_time)
			{
				print_status(info, philo->key, "died\n");
				info->die = 1;
			}
			pthread_mutex_unlock(&info->eat_check);
			usleep(100);
		}
		if (info->die)
			break;
		i = 0;
		while (info->must_eat != -1 && i < info->num && philo[i].eat_count >= info->must_eat)
			i++;
		if (i >= info->num)
			info->all_ate = 1;
	}
}