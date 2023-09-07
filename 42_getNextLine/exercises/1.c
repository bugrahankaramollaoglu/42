#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	FILE	*filePointer;
	int		bufferLength;

	bufferLength = 255;
	char buffer[bufferLength]; 
	filePointer = fopen("file", "r");
	while (fgets(buffer, bufferLength, filePointer))
	{
		printf("%s", buffer);
	}
	fclose(filePointer);
}
