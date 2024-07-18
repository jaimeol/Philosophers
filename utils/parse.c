/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:30:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/18 12:32:18 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philosophers.h"

int	is_valid_number(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (sign && (str[i - 1] == '-' || str[i - 1] == '+'))
		return (1);
	return (0);
}
