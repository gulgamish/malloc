/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alloc_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:43:18 by aelamran          #+#    #+#             */
/*   Updated: 2020/11/14 19:49:01 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	ft_print_alloc_info(t_memory *cur)
{
	size_t	total;

	total = 0;
	while (cur->next)
	{
		printf("%p - %p : %zu bytes\n",cur->block_addr, cur->next, cur->block_size);
		total += cur->block_size;
		cur = cur->next;
	}
	return (total);
}
