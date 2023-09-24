#include <stdio.h>
#include <sys/time.h> // Include the header for gettimeofday

int main()
{
	struct timeval tv;
	unsigned long long time;

	// Get the current time
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return 1;
	}

	// Print the current time in seconds and microseconds
	printf("Seconds: %ld\n", tv.tv_sec);
	printf("Microseconds: %ld\n", tv.tv_usec);

	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("Milliseconds: %llu\n", time);
	return 0;
}
