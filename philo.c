/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:26:21 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/16 18:06:40 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_eat(void *data)
{	
	struct timeval p_time;
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->mutex);
	gettimeofday(&p_time, NULL);
	printf("%ld %d is eating\n", p_time.tv_sec / 1000, philo->key);
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

void *ft_sleep(void *data)
{
	struct timeval p_time;
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->mutex);
	printf("%ld %d is sleeping\n", p_time.tv_sec / 1000, philo->key);
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

void *ft_think(void *data)
{
	struct timeval p_time;
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->mutex);
	printf("%ld %d is thinking\n", p_time.tv_sec / 1000, philo->key);
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

void *ft_die(void *data)
{
	struct timeval p_time;
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->mutex);
	printf("%ld %d is died\n", p_time.tv_sec / 1000, philo->key);
	pthread_mutex_unlock(philo->mutex);
	return (0);
}