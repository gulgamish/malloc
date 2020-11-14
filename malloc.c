#include "malloc.h"

int	set_memory()
{
	mem[0].memory_size = TINY;
	if ((mem[0].ptr = 
	mmap(NULL, TINY, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
		return (-1);
	mem[1].memory_size = SMALL;
	if ((mem[1].ptr = mmap(NULL, SMALL, PROT_READ
					| PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
		return (-1);
	mem[2].memory_size = LARGE;
	return (1);
}

void	show_alloc_mem(void)
{
	void	*ptr;
	int	i;

	ptr = mem[0].ptr;
	i = 0;
	printf("TINY : %p\n", ptr);
	while (mem[0].allocated_bytes[i] != 0)
	{
		printf("%p - %p : %d bytes\n", ptr,
				ptr + mem[0].allocated_bytes[i], (int)mem[0].allocated_bytes[i]);
		ptr = ptr + mem[0].allocated_bytes[i];
		i++;
	}
}

void	*alloc_tiny_mem(size_t size)
{
	void	*ptr;
	void	*addr;
	int	i;

	ptr = mem[0].ptr;
	i = 0;
	while (mem[0].allocated_bytes[i] != 0)
	{
		ptr = ptr + mem[0].allocated_bytes[i];
		i++;
	}
	addr = ptr;
	mem[0].allocated_bytes[i] = size;
	return (addr);
}

void	*ft_malloc(size_t size)
{
	void	*addr;

	if (set_memory() == -1)
		return (NULL);
	if (size <= mem[0].memory_size)
		addr = alloc_tiny_mem(size);
	/*else if (size <= mem[1].memory_size)
	  alloc_small_mem(size);
	  else
	  alloc_large_mem();*/
	return (addr);
}
