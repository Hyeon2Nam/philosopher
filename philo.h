/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/24 14:25:27 by hyenam           ###   ########.fr       */
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
	struct s_philo *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t eat_check;
	pthread_mutex_t s_print;
	uint64_t start;
	uint64_t die_time;
	uint64_t eat_time;
	uint64_t sleep_time;
	int must_eat;
	int num;
	int die;
	int all_ate;

} t_info;

typedef struct s_philo
{
	t_info *info;
	pthread_t thr;
	// pthread_t die;
	uint64_t end_eat;
	int key;
	int is_eat;
	int eat_count;
	int left_fork;
	int right_fork;
} t_philo;

int find_null(int argc, char *args[]);
int data_parse(int argc, char *args[], int *data);

int info_init(t_info *info, int *data);
int philo_init(t_info *info);

int create_thread(t_info *info);
int create_mutex(t_info *info);
void reset(t_info *info);

void *philo_action(void *data);
void ft_eat(t_philo *philo);
void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);

void monitor_die(t_info *info, t_philo *philo);
// void *monitor_die(void *data);
int monitor_eat(t_info *info, t_philo *philo);

void print_status(t_info *info, int key, char *str);
uint64_t get_time(void);
void ft_usleep(int ms);

char **ft_split(char const *s, char c);
int ft_splitlen(char **str);
int ft_atoi(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *s);
void ft_free(char **arr);

#endif