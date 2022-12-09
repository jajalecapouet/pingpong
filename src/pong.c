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
	fprintf(stderr, "pong launched\n");
	while (1)
	{
		fgets(line, 48, stdin);
		fprintf(stderr, "%s", line);
		sleep(1);
		printf("coucou\n");
	}
}