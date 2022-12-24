/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:17 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/25 02:46:29 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		error_control("File open Error\n");
	dup2(infile_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	executer(argv[2], envp);
}

void	parents_process(char **argv, char **envp, int *fd)
{
	int	outfile_fd;

	outfile_fd = open(argv[4], O_RDWR | O_CREAT);
	if (outfile_fd == -1)
		error_control("File open Error\n");
	dup2(outfile_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	executer(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		error_control("check command\n");
	if (pipe(pipe_fd) == -1)
		error_control("Pipe Error\n");
	pid = fork();
	if (pid == 0)
		child_process(argv, envp, pipe_fd);
	waitpid(pid, NULL, 0);
	parents_process(argv, envp, pipe_fd);
}
