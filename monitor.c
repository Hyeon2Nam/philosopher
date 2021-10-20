/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/20 16:19:24 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_exit(t_info *info)
{
    free(info->forks);
    free(info->philos);
    free(info);
    exit(0);
}

void *monitor_die(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (1)
    {
        pthread_mutex_lock(&philo->die);
        if (!philo->is_eat && get_time() > philo->end_eating + philo->info->die_time)
        {
            print_status(philo, "die\n");
            philo->info->death = 1;
            exit(0);
            return ((void *)1);
            // ft_exit(info);
        }
        pthread_mutex_unlock(&philo->die);
    }
    return (0);
}

void *monitor_eat(void *data)
{
    t_info *info;
    int done;
    int i;

    info = (t_info *)data;
    done = 0;
    while (done < info->num)
    {
        i = -1;
        while (++i < info->num)
            if (info->philos[i].eat_count == info->must_eat)
                done++;
    }
    exit(0);
    return (0);
}