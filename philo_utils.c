/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:22:23 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/24 15:08:51 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(info->forks);
	free(info->philos);
	info->philos = NULL;
}

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < (uint64_t)ms)
		usleep(100);
	return ;
}

void	print_status(t_info *info, int key, char *str)
{
	pthread_mutex_lock(&info->s_print);
	if (!info->die)
		printf("%lld %d %s", get_time() - info->start, key, str);
	pthread_mutex_unlock(&info->s_print);
}
