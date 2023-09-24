#include <stdio.h>
#include <unistd.h> // Include the header for usleep

int main()
{
	printf("Delaying for 1 second...\n");
	usleep(1000000); // Delay for 1 second (1000000 microseconds)

	printf("Delay complete!\n");
	return 0;
}
