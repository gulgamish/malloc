/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newblock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:59:18 by aelamran          #+#    #+#             */
/*   Updated: 2020/11/14 18:26:32 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_newblock(size_t size, int memory_type)
{
	t_memory *new_block;
	t_memory *cur;

	if (memory_type == 0)
		cur = mem[0];
	else if (memory_type == 1)
		cur = mem[1];
	while (cur->next)
		cur = cur->next;
	new_block = cur;
	new_block->block_addr =(t_memory *)((size_t)new_block + sizeof(t_memory));
	new_block->block_size = size;
	new_block->is_freed = 0;
	new_block->next = new_block + sizeof(t_memory) + size;
	cur = new_block;
	return (new_block->block_addr);
}
