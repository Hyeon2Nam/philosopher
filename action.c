/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:20:25 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/26 13:11:46 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->left_fork]);
	print_status(info, philo->key, "has taken a fork\n");
	pthread_mutex_lock(&info->forks[philo->right_fork]);
	print_status(info, philo->key, "has taken a fork\n");
	philo->end_eat = get_time();
	print_status(info, philo->key, "is eating\n");
	ft_usleep((philo->info->eat_time));
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void	ft_sleep(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	print_status(info, philo->key, "is sleeping\n");
	ft_usleep(philo->info->sleep_time);
}

void	ft_think(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	print_status(info, philo->key, "is thinking\n");
}

void	monitor_die(t_info *info, t_philo *philo)
{
	int	i;

	while (!info->die)
	{
		i = -1;
		while (++i < info->num && !info->die)
		{
			if ((get_time() - philo[i].end_eat) >= info->die_time)
			{
				print_status(info, philo[i].key, "died\n");
				info->die = 1;
			}
		}
		if (info->die || info->all_ate)
			break ;
	}
}

int	monitor_eat(t_info *info, t_philo *philo)
{
	if (philo->eat_count >= info->must_eat)
		info->all_ate++;
	if (info->all_ate >= info->num)
		return (1);
	return (0);
}
