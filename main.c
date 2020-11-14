#include "malloc.h"

int main(void)
{
	void	*ptr = ft_malloc(6);
	void	*ptr2 = ft_malloc(sizeof(int) * 5);
	void	*ptr3 = ft_malloc(1);
	show_alloc_mem();
	return (0);
}
