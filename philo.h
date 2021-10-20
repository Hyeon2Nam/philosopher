/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/20 16:48:32 by hyenam           ###   ########.fr       */
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

struct s_philo;

typedef struct s_info
{
	pthread_mutex_t *forks;
	pthread_mutex_t action;
	pthread_mutex_t s_print;
	pthread_t monitor;
	uint64_t start;
	uint64_t die_time;
	uint64_t eat_time;
	uint64_t sleep_time;
	int must_eat;
	int death;
	int num;
	struct s_philo *philos;
} t_info;

typedef struct s_philo
{
	pthread_mutex_t die;
	pthread_t thr;
	uint64_t end_eating;
	int is_eat;
	int right_fork;
	int left_fork;
	int eat_count;
	int key;
	t_info *info;
} t_philo;

int find_null(int argc, char *args[]);
int data_parse(int argc, char *args[], int *data);
void info_init(t_info *info, int *data);
int create_thread(t_info *info);
void *create_mutex(t_info *info);

void *philo_action(void *data);
void ft_get_fork(t_philo *philo);
void ft_eat(t_philo *philo);
void ft_off_fork(t_philo *philo);
void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);

void *monitor_die(void *data);
void *monitor_eat(void *data);
void ft_exit(t_info *info);

void print_status(t_philo *philo, char *str);
uint64_t get_time(void);
void ft_usleep(int ms);

char **ft_split(char const *s, char c);
int ft_splitlen(char **str);
int ft_atoi(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *s);
void ft_free(char **arr);

#endif