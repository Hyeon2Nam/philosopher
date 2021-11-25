/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:34:50 by hyenam            #+#    #+#             */
/*   Updated: 2021/11/25 19:44:37 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	info_init(t_info *info, int data[5])
{
	info->num = data[0];
	info->die_time = data[1];
	info->eat_time = data[2];
	info->sleep_time = data[3];
	info->must_eat = data[4];
	info->all_ate = 0;
	info->die = 0;
	if (philo_init(info))
		return (1);
	return (0);
}

int	data_parse(int argc, char *args[], int data[5])
{
	char	**temp;
	int		cnt;
	int		i;
	int		j;

	i = 0;
	cnt = 0;
	while (++i < argc)
	{
		j = 0;
		temp = ft_split(args[i], ' ');
		if (ft_splitlen(temp) + cnt > 5)
			return (1);
		while (j < ft_splitlen(temp))
		{
			if (ft_atoi(temp[j]) < 0)
				return (1);
			data[cnt++] = ft_atoi(temp[j++]);
		}
		ft_free(temp);
	}
	if (!data[3])
		return (1);
	return (0);
}

int	find_null(int argc, char *args[])
{
	int	i;

	i = 0;
	while (++i < argc)
		if (args[i][0] == '\0')
			return (1);
	return (0);
}
