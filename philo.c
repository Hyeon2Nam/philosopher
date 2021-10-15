/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:26:21 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/15 17:50:17 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(void *data, pthread_mutex_t *mutex)
{
	char thread_name;

	thread_name = (char *)data;
	pthread_mutex_lock(mutex);
	printf("%s eat",thread_name);
	pthread_mutex_unlock(mutex);
}

void think(void *data, pthread_mutex_t *mutex)
{
	char thread_name;

	thread_name = (char *)data;
	pthread_mutex_lock(mutex);
	printf("%s think",thread_name);
	pthread_mutex_unlock(mutex);
}

void sleep(void *data, pthread_mutex_t *mutex)
{
	char thread_name;

	thread_name = (char *)data;
	pthread_mutex_lock(mutex);
	printf("%s sleep",thread_name);
	pthread_mutex_unlock(mutex);
}

void die(void *data, pthread_mutex_t *mutex)
{
	char thread_name;

	thread_name = (char *)data;
	pthread_mutex_lock(mutex);
	printf("%s die",thread_name);
	pthread_mutex_unlock(mutex);
}