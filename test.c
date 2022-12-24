/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:51:05 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/24 22:09:38 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int main(int argc, char **argv, char **envp)
{
	int i;

	i = 0;

	while (envp[i])
	{
		printf("%s\n",envp[i++]);
	}
}

// int main()
// {
// 	pid_t pid;
// 	int filein;
// 	int fileout;
// 	int	fd[2];

// 	pid = fork();
// 	filein = open("infile.txt", O_RDONLY);
// 	fileout = open("outfile.txt", O_RDWR | O_CREAT);
// 	if(filein < 0 || fileout < 0)
// 		perror("file error");
// 	pipe(fd);
// 	dup2(filein, 0);
// 	if (pid == 0)
// 	{
// 		char *argv[] = { "./wc", NULL};
// 		dup2(fd[1],1);
// 		execve("/usr/bin/wc", argv, NULL);
// 	}
// 	else
// 	{
// 		char *argv[] = { "./wc", NULL};

// 		dup2(fd[0], 0);
// 		dup2(fileout, 1);
// 		waitpid(pid, NULL, 0);
// 		execve("/usr/bin/wc", argv, NULL);
// 	}
// }
