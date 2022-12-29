/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:01 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/29 19:52:48 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**build_cmd_box(char **box, char *s)
{
	int		i;
	int		j;
	int		k;
	char	**rtn;

	i = 0;
	while (box && box[i])
		i++;
	rtn = (char **)malloc(sizeof(char *) * (i + 2));
	j = -1;
	k = 0;
	while (++j < i)
		rtn[j] = ft_strdup(box[j]);
	rtn[j] = s;
	rtn[i + 1] = NULL;
	free_box(box);
	return (rtn);
}

char	*erase_quote(char *s)
{
	size_t	i;
	char	flag;
	char	*rtn;
	char	*tmp;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!flag && s[i] == '\'' || s[i] == '"')
			flag = s[i];
	}
}

char	**parse_quote(char *cmd)
{
	int		i;
	int		j;
	char	flag;
	char	**rtn;

	rtn = NULL;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ')
			i++;
		j = 0;
		flag = 0;
		while (cmd[i + j] && (flag || cmd[i + j] != ' ') && cmd[i + j] != flag)
		{
			if (!flag && (cmd[i + j] == '"' || cmd[i + j] == '\''))
				flag = cmd[i + j];
			j++;
		}
		rtn = build_cmd_box(rtn, ft_strndup(&cmd[i], j));
		i = i + j;
	}
	return (rtn);
}
