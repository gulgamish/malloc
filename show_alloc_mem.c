#include "malloc.h"

void	show_alloc_mem(void)
{
	void	*ptr;
	int	i;

	ptr = mem[0].ptr;
	i = 0;
	printf("TINY : %p\n", mem[0].ptr);
	while (mem[0].allocated_bytes[i] != 0)
	{
		printf("%p - %p : %d bytes\n", ptr,
				ptr + mem[0].allocated_bytes[i], (int)mem[0].allocated_bytes[i]);
		ptr = ptr + mem[0].allocated_bytes[i];
		i++;
	}
}
