/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excuter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:11:11 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/04 16:18:55 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*rtn;

	while (envp && *envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (envp && *envp)
	{
		paths = ft_split(&(*envp)[5], ':');
		i = 0;
		while (paths[i])
		{
			rtn = ft_strjoin(paths[i++], cmd);
			if (access(rtn, F_OK) == 0)
			{
				free(cmd);
				free_box(paths);
				return (rtn);
			}
			free(rtn);
		}
		free_box(paths);
	}
	free(cmd);
	return (NULL);
}

void	executer(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = parse_argv(cmd);
	path = find_path(ft_strjoin("/", argv[0]), envp);
	if (!path)
		path = argv[0];
	if (execve(path, argv, envp) == -1)
		error_control("command not found: ", argv[0], 127);
}
