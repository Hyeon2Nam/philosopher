/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:26:21 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/19 12:38:39 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_status(philo, "has taken a fork\n");
	philo->is_eat = 1;
	print_status(philo, "is eating\n");
	ft_usleep((philo->info->eat_time));
	philo->end_eating = get_time();
	philo->eat_count++;
	philo->is_eat = 0;
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}

void ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->action);
	print_status(philo, "is sleeping\n");
	ft_usleep(philo->info->sleep_time);
	pthread_mutex_unlock(&philo->info->action);
}

void ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->action);
	print_status(philo, "is thinking\n");
	pthread_mutex_unlock(&philo->info->action);
}
