#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>

#define TINY getpagesize()
#define SMALL (TINY + 1) + getpagesize() * 2
#define LARGE (SMALL + 1)

typedef struct		s_memory
{
	size_t		memory_size;
	struct s_memory	*next;
	void		*data;
}			t_memory;

static t_memory	mem[3] = { 0 };

void	*alloc_tiny_mem(size_t size);
void	show_alloc_mem(void);
void	*ft_malloc(size_t size);

#endif
