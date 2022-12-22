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
		read(0, line, 20);
		fprintf(stderr, "pong : ping said to me %s", line);
		sleep(1);
		write(1, "PONG!\n", 7);
	}
}