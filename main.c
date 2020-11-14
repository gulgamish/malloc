#include "malloc.h"

int main(void)
{
	void	*ptr = ft_malloc(6);
	void	*ptr2 = ft_malloc(sizeof(int) * 5);
	void	*ptr3 = ft_malloc(1);
	void	*ptr6 = ft_malloc(50);
	void	*ptr7 = ft_malloc(100);
	void	*ptr8 = ft_malloc(7002);
	show_alloc_mem();
	return (0);
}
