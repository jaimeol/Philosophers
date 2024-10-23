/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:24 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/18 16:21:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_here_doc(t_mini *mini)
{
	if (mini->here_doc == 1)
	{
		unlink("here_doc");
		mini->here_doc = 0;
	}
}

int	check_infile(int infile)
{
	if (infile < 0)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}

int	check_outfile(int outfile)
{
	if (outfile < 0)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}

int	check_echo_next_pos(char **str, int i)
{
	if (!str[i + 1])
	{
		printf("\n");
		return (1);
	}
	return (0);
}
