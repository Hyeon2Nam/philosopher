/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/19 12:39:02 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_exit(t_info *info)
{
    free(info->forks);
	free(info->philos);
    free(info);
}

void *monitor_action(void *data)
{
    t_info *info;
    int done;
    int i;

    info = (t_info *)data;
    while (info->death == 0)
    {
        done = 0;
        i = -1;
        while (++i < info->num)
        {
            if (!info->philos[i].is_eat && get_time() > info->philos[i].end_eating + info->die_time)
            {
                print_status(&info->philos[i], "die\n");
                info->death = 1;
                exit(0);
            }
            if (info->must_eat != -1 && info->philos[i].eat_count == info->must_eat)
                done++;
            if (done == info->num)
                exit(0);
        }
    }
    return (0);
}