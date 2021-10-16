/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/16 18:00:28 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
	int num;
	int die_time;
	int eat_time;
	int sleep_time;
	int must_eat;
} t_info;

typedef struct s_philo
{
	pthread_mutex_t *mutex;
	pthread_t thr;
	int key;
	t_info *info;
} t_philo;

int find_null(int argc, char *args[]);
int data_parse(int argc, char *args[], int *data);
void info_init(t_info *info, int *data);

void create_philo(t_info *info);

void *ft_eat(void *data);

char **ft_split(char const *s, char c);
int ft_splitlen(char **str);
int ft_atoi(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *s);

#endif