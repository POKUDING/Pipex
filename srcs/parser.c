/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:05:01 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/29 14:22:57 by junhyupa         ###   ########.fr       */
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
	free_box(box);
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

char	**parse_quote(char **argv)
{
	int		i;
	int		j;
	char	flag;

	i = 1;
	flag = 0;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j] && (flag || argv[i][j] != ' '))
		{
			if (!flag && argv[i][j] == '"' || argv[i][j] == '\'')
				flag = j;
			else if (flag && flag == argv[i][j])
				flag = 0;
			else if (!flag && argv[i][j] == ' ')
				break;
			j++;
		}
		argv = build_cmd_box(argv , j);
		i++;
	}
	return (argv);
}
