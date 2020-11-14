#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "malloc.h"

int main(void)
{
	t_memory *tiny_mem;
	t_memory *cur;
	t_memory *dummy;
	t_memory *addr;
	char	*str;
	char	*str2;

	tiny_mem = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (tiny_mem == MAP_FAILED)
	{
		perror("mmap");
		return (0);
	}
	tiny_mem->memory_size = 20;
	tiny_mem->next = NULL;
	//printf("%p, %p, %p, %p\n", tiny_mem, &tiny_mem->memory_size, &tiny_mem->next, &tiny_mem->data);
	addr = (t_memory *)((size_t)&tiny_mem->data + tiny_mem->memory_size);
	cur = tiny_mem->next = addr;
	cur->memory_size = 10;
	cur->next = NULL;
	str = (char *)&tiny_mem->data;
	strcpy(str, "aymanaymanaymanaymanaymanaymanaymanaymanaymanayman");
	puts(str);
	str2 = (char *)&cur->data;
	strcpy(str2, "imane");
	puts(str2);
	while(tiny_mem)
	{
		printf("%p - %p, %d bytes\n", &tiny_mem->data,(void *)((size_t)&tiny_mem->data + tiny_mem->memory_size), tiny_mem->memory_size);
		tiny_mem = tiny_mem->next;
	}
	return (0);
}
