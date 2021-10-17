/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:48:03 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/17 21:36:32 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void ft_usleep(int ms)
{
	uint64_t start;
	
	start = get_time();
	while (get_time() - start < (uint64_t)ms)
		usleep(100);
	return ;
}

void print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->s_print);
	printf("%lld %d %s", get_time() - philo->info->start, philo->key, str);
	pthread_mutex_unlock(&philo->info->s_print);
}
