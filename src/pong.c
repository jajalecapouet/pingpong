#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char line[20];
	line[19] = 0;
	fprintf(stderr, "pong : Me too !\n");
	while (1)
	{
		fgets(line, 48, stdin);
		fprintf(stderr, "pong : ping said to me \"%s\"\n", line);
		sleep(1);
		printf("PONG!\n");
	}
}