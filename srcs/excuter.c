/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excuter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:11:11 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/30 19:43:52 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*rtn;

	i = 0;
	while (ft_strncmp("PATH=", envp[i++], 5))
		;
	paths = ft_split(&envp[i - 1][5], ':');
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
		error_control("command not found");
	if (execve(path, argv, envp) == -1)
		error_control("execve_failed");
}
