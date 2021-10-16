/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:34:50 by hyenam            #+#    #+#             */
/*   Updated: 2021/10/16 17:53:44 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void info_init(t_info *info, int data[5])
{
	info->num = data[0];
	info->die_time = data[1];
	info->eat_time = data[2];
	info->sleep_time = data[3];
	if (data[4])
		info->must_eat = data[4];
	else
		info->must_eat = 0;
}

int data_parse(int argc, char *args[], int data[5])
{
	char **temp;
	int cnt;
	int i;
	int j;

	i = 0;
	cnt = 0;
	while (++i < argc)
	{
		j = 0;
		temp = ft_split(args[i], ' ');
		if (temp && cnt >= 5)
			return (1);
		if (ft_splitlen(temp) + cnt > 5)
			return (1);
		while (j < ft_splitlen(temp))
		{
			if (ft_atoi(temp[j]) < 0)
				return (1);
			data[cnt++] = ft_atoi(temp[j++]);
		}
	}
	if (!data[3])
		return (1);
	//나중에 지움 확인용
	for (int i = 0; i < 5; i++)
		printf("data[%d]:%d\n", i, data[i]);
	return (0);
}

int find_null(int argc, char *args[])
{
	int i;

	i = 0;
	while (++i < argc)
		if (args[i][0] == '\0')
			return (1);
	return (0);
}