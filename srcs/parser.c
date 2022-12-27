/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:01 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/27 16:25:22 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**build_cmd_box(char **box ,int n)
{
	int		i;
	int		j;
	int		k;
	char	**rtn;

	i = 0;
	while (box[i])
		i++;
	rtn = (char **)malloc(sizeof(char *) * (i + 2));
	j = -1;
	k = 0;
	while (++j < i - 1)
		rtn[j] = ft_strdup(box[j]);
	rtn[j] = ft_strndup(box[j], n);
	rtn[j+1] = ft_strdup(box[j] + n + 1);
	rtn[i + 1] = NULL;
	return (rtn);
}

char	*erase_quote(char *s, char c)
{
	int		i;
	int		j;
	int		count_quote;
	char	*rtn;

	i = -1;
	count_quote = 0;
	while (s[++i] && i < ft_strlen(s))
	{
		if (s[i] == c)
			count_quote++;
	}
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) - count_quote + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			rtn[j++] = s[i++];
		else
			i++;
	}
	free (s);
	return (rtn);
}

char	**parse_argv(char *cmd)
{
	char **rtn;
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	rtn = ft_cutstr(cmd);
	while(rtn[i])
	{
		j = 0;
		while(rtn[i][j] && (flag || rtn[i][j] != ' ')
		{
			if (j == '"' || j == "'")
				flag = !flag;
			j++;
		}
	}
}
