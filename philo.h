/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/17 16:59:38 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_info
{
	pthread_mutex_t *forks;
	pthread_mutex_t action;
	pthread_mutex_t s_print;
	pthread_t monitor;
	struct timeval time_status;
	int num;
	int die_time;
	int eat_time;
	int sleep_time;
	int must_eat;
	int death;
	int start;
} t_info;

typedef struct s_philo
{
	pthread_t thr;
	long long start_eating;
	long long end_eating;
	int right_fork;
	int left_fork;
	int eat_count;
	int key;
	t_info *info;
} t_philo;

int find_null(int argc, char *args[]);
int data_parse(int argc, char *args[], int *data);
void info_init(t_info *info, int *data);
void *philo_action(void *data);
void print_status(t_philo *philo, int ms, char *str);

void create_philo(t_info *info);

void ft_eat(t_philo *philo);
void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);

char **ft_split(char const *s, char c);
int ft_splitlen(char **str);
int ft_atoi(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *s);
void ft_free(char **arr);

#endif