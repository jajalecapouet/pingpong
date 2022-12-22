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
	fprintf(stderr, "ping : I'm alive !\n");
	while (1)
	{
		sleep(1);
		write(1, "PING!\n", 7);
		read(0, line, 20);
		fprintf(stderr, "ping : pong said to me %s", line);
	}
}