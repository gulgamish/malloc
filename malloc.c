/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:13:46 by aelamran          #+#    #+#             */
/*   Updated: 2020/11/14 20:46:19 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	set_memory(size_t size)
{
	if (!mem[0] || (size <= TINY && ft_is_memory_saturated(mem[0], size, TINY)))
	{
		if (mem[0])
			if (munmap((void *)mem[0], TINY) == -1)
				return (-1);
		if ((mem[0] = (t_memory *)mmap(NULL, TINY, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
			return (-1);
	}
	if (!mem[1] || (size <= SMALL && ft_is_memory_saturated(mem[0], size, SMALL)))
	{
		if (mem[1])
			if (munmap((void *)mem[0], TINY) == -1)
				return (-1);
		if ((mem[1] = (t_memory *)mmap(NULL, SMALL, PROT_READ
					| PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
			return (-1);
	}
	return (1);
}

void	show_alloc_mem()
{
	t_memory	*cur;
	size_t		total;

	total = 0;
	cur = mem[0];
	printf("TINY: %p\n", cur);
	if (cur)
		total += ft_print_alloc_info(cur);
	cur = mem[1];
	printf("SMALL: %p\n", cur);
	if (cur)
		total += ft_print_alloc_info(cur);
	cur = mem[2];
	printf("LARGE: %p\n", cur);
	if (cur)
		total += ft_print_alloc_info(cur);
	printf("Total : %zu bytes\n", total);
}

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
	new_block->next = (t_memory *)((size_t)new_block + sizeof(t_memory) + size);
	cur = new_block;
	return (new_block->block_addr);
}

void	*ft_malloc(size_t size)
{
	void	*addr;

	if (set_memory(size) == -1)
		return (NULL);
	//printf("%p\n", mem[0]);
	if (size <= TINY)
		addr = ft_newblock(size, 0);
	else if (size <= LARGE)
		addr = ft_newblock(size, 1);
	  /*else
	  alloc_large_mem();*/
	return (addr);
}
