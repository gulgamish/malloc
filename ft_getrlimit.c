#include <stdio.h>
#include <sys/resource.h>
#include <string.h>

int	main(void)
{
	struct rlimit	limit;

	memset((void *)&limit, 0, sizeof(limit));
	if (getrlimit(RLIMIT_DATA, &limit) != 0)
	{
		perror("getrlimit");
		return (0);
	}
	printf("soft limit: %zu, hard limit: %zu\n", (size_t)limit.rlim_cur, (size_t)limit.rlim_max);
	return (0);
}
