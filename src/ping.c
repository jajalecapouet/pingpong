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
	fprintf(stderr, "ping launched\n");
	while (1)
	{
		sleep(1);
		printf("hello\n");
		fgets(line, 48, stdin);
		fprintf(stderr, "%s", line);
	}
}