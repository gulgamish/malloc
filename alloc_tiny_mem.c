#include "malloc.h"

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
