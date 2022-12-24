/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:56:10 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/24 23:56:06 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void error_control(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void free_box(char **box)
{
	int	i;

	i = 0;
	while(box[i])
		free(box[i++]);
	free(box);
}

char *find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*rtn;

	i = 0;
	while(ft_strncmp("PATH=",envp[i++],5));
	paths = ft_split(&envp[i][5], ':');
	while(paths[i])
	{
		rtn = ft_strjoin(paths[i++], cmd);
		if(access(rtn, F_OK) == 0)
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
	char	path;

	argv = ft_split(cmd, ' ');
	path = find_path(ft_strjoin("/",argv[0]),envp);
	if (!path)
		error_control(1);

}
