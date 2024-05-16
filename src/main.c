/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:19 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/16 18:24:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    arg_error(void)
{
    printf("Incorrect usage.\nExample: ./Philosophers [philosophers number] ");
    printf("[time to die] [time to eat] [time to sleep] ");
    printf("[number of times philosophers must eat]\n");
    printf("\033[0;31mLast Parameter is optional\033[0m\n");
    exit(1);
}

int main (int argc, char **argv)
{
    if (argc < 5)
        arg_error();
    printf("%c", argv[1][1]);
    return (0);
}