/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:01 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/30 16:35:28 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**build_cmd_box(char **box, char *s)
{
	int		i;
	int		j;
	char	**rtn;

	i = 0;
	if (s[0] == '"' || s[0] == '\'')
		//quote 없애기
	if (s[i] == ' ')
	{
		//새라인 만들기
	}
	else
	{
		//라인 이어 붙이기
	}
}

char	*join_argv(char *argv, char *new)
{
	size_t	i;
	char	*tmp;
	char	*rtn;

	if (new[0] == "'")
	if (argv == NULL)
	{
		rtn = ft_strtrim(new, )
	}
}

char	**parse_quote(char *cmd)
{
	int		i;
	int		j;
	char	flag;
	char	*tmp;
	char	**rtn;

	rtn = NULL;
	i = 0;
	while (cmd[i])
	{
		j = 0;
		while(cmd[i + j] == ' ')
			j++;
		flag = 0;
		if ((cmd[i + j] == '"' || cmd[i + j] == '\''))
			flag = cmd[i + j];
		while (cmd[i + j] && (flag || cmd[i + j] != ' ') && cmd[i + j] != flag)
			j++;
		rtn = build_cmd_box(rtn, ft_strndup(&cmd[i], j));
		i = i + j;
	}
	return (rtn);
}
