/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:26:21 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/17 17:08:27 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	gettimeofday(&philo->info->time_status, NULL);
	philo->start_eating = philo->info->start - (philo->info->time_status.tv_sec / 1000);
	print_status(philo, philo->start_eating, "has taken a fork\n");
	print_status(philo, philo->start_eating, "is eating\n");
	usleep(philo->info->eat_time / 1000);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	gettimeofday(&philo->info->time_status, NULL);
	philo->end_eating = philo->info->time_status.tv_sec / 1000;
	if (philo->info->must_eat != -1)
		philo->eat_count++;
	// print_status(philo, "done\n");
}

void ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->action);
	usleep(philo->info->sleep_time * 1000);
	// print_status(philo, "is sleeping\n");
	pthread_mutex_unlock(&philo->info->action);
}

void ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->action);
	// print_status(philo, "is thinking\n");
	pthread_mutex_unlock(&philo->info->action);
}

void print_status(t_philo *philo, int ms, char *str)
{
	pthread_mutex_lock(&philo->info->s_print);
	printf("%d %d %s", ms, philo->key, str);
	pthread_mutex_unlock(&philo->info->s_print);
}