/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:17 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/04 16:39:14 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if(pipe(fd) == -1)
		error_control("pipe error\n", NULL, 1);
	pid = fork();
	if (pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		executer(argv, envp);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}


int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile_fd;
	int	outfile_fd;

	if (argc < 5)
		error_control("check command\n", NULL, 1);
	i = 2;
	outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (i < argc - 2)
		child_process(argv[i], envp, pipe_fd);
	dup2(outfile_fd, STDOUT_FILENO);
	executer(argv[i], envp);
}
