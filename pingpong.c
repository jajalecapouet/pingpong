#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	pingpong(char *path1, char *path2)
{
	int	pid_fork1;
	int pid_fork2;

	if (access(path1, X_OK))
		return (-1);
	if (access(path2, X_OK))
		return (-1);
	pid_fork1 = fork();
	if (pid_fork1 == -1)
		return (-1);
	pid_fork2 = fork();
	if (pid_fork2 == -1)
		return (-1);
	if (pid_fork1 == 0)
	{
		execve()
	}
}

int main(int ac, char **av)
{
	int	err;

	if (ac != 3)
	{
		write(2, "erreur d'E/S\n", 14);
		exit(1);
	}
	err = pingpong(av[1], av[2]);
}
