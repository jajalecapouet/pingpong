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
		printf("PING!\n");
		//fgets(line, 48, stdin);
		unsigned char	c = fgetc(stdin);
		while (c != EOF && c != '\n')
			fprintf(stderr, "%c", c);
		fprintf(stderr, "\n");
		fprintf(stderr, "ping : pong said to me \"lul\"\n");
	}
}