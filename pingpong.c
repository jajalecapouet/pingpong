#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void	solver_fork(char *path, char **env, int *pipe_out, int *pipe_in)
{
	int	solver_return;
	char	*execve_null_strs[1];

	if (dup2(pipe_in[0], STDIN_FILENO) == -1)
		write(2, "dup2 error\n", 12);
	if (dup2(pipe_out[1], STDOUT_FILENO) == -1)
		write(2, "dup2 error\n", 12);
	execve_null_strs[0] = 0;
	solver_return = execve(path, execve_null_strs, env);
	exit(solver_return);
}

void	subject_fork(char **path, char **env, int *pipe_out, int *pipe_in)
{
	int	subject_return;

	if (dup2(pipe_in[0], STDIN_FILENO) == -1)
		write(2, "dup2 error\n", 12);
	if (dup2(pipe_out[1], STDOUT_FILENO) == -1)
		write(2, "dup2 error\n", 12);
	subject_return = execve(path[0], path, env);
}

int	pingpong(char *path1, char **path2, char **env)
{
	int	pid_fork1;
	int pid_fork2;
	int	pipe_solver_to_subject[2];
	int	pipe_subject_to_solver[2];

	if (pipe(pipe_solver_to_subject))
	{
		write(2, "pipe error\n", 12);
		return (-1);
	}
	if (pipe(pipe_subject_to_solver))
	{
		write(2, "pipe error\n", 12);
		return (-1);
	}
	if (access(path1, X_OK))
	{
		write(2, "access error\n", 14);
		return (-1);
	}
	if (access(path2[0], X_OK))
	{
		write(2, "access error\n", 14);
		return (-1);
	}
	pid_fork1 = fork();
	if (pid_fork1 == -1)
	{
		write(2, "fork error\n", 12);
		return (-1);
	}
	pid_fork2 = fork();
	if (pid_fork2 == -1)
	{
		write(2, "fork error\n", 12);
		return (-1);
	}
	if (pid_fork1 == 0)
		solver_fork(path1, env, pipe_solver_to_subject, pipe_solver_to_subject);
	else if (pid_fork2 == 0)
		subject_fork(path2, env, pipe_subject_to_solver, pipe_solver_to_subject);
	else
	{
		if (waitpid(pid_fork2, NULL, 0) == -1)
		{
			write(2, "subject crashed\n", 17);
			return (-1);
		}
		kill(pid_fork1, SIGINT);
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	int	err;

	if (ac < 3)
	{
		write(2, "how to use : ./pingpong + ./solver + ./subject + [subjet-opt]\n", 63);
		exit(1);
	}
	err = pingpong(av[1], &av[2], env);
}
