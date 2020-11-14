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
	void			*block_addr;
	size_t			block_size;
	int				is_freed;
	struct s_memory	*next;
}					t_memory;

static t_memory	*mem[3] = { 0 };

void		show_alloc_mem();
int			ft_is_memory_saturated(t_memory *memory, size_t size, size_t memory_zone);
size_t		ft_print_alloc_info(t_memory *cur);
void		*ft_malloc(size_t size);

#endif
