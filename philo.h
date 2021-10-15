/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/15 17:55:45 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	pthread_mutex_t *mutex;
	pthread_t thr;
	int key;
}	t_philo;



void *thread(void *data);
void eat(void *data, pthread_mutex_t *mutex);
void think(void *data, pthread_mutex_t *mutex);
void sleep(void *data, pthread_mutex_t *mutex);
void die(void *data, pthread_mutex_t *mutex);

#endif