/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:15:44 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/17 11:29:32 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philosophers.h"

long int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;
	size_t	i;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = (res + str[i] - '0') * 10;
		i++;
	}
	res = (res / 10) * sign;
	return (res);
}
