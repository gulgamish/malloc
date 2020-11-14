/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_memory_saturated.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:44:48 by aelamran          #+#    #+#             */
/*   Updated: 2020/11/14 20:45:04 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	ft_is_memory_saturated(t_memory *memory, size_t size, size_t memory_zone)
{
	t_memory	*cur;
	size_t 		sum;

	cur = memory;
	sum = 0;
	while (cur->next)
	{
		sum += cur->block_size;
		cur = cur->next;
	}
	if (sum + size > memory_zone)
		return (1);
	return (0);
}
