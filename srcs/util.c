/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:56:10 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/04 16:43:07 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_control(char *msg, char *msg2, int n)
{
	char	*output;

	if (msg2)
		output = ft_strjoin(msg, msg2);
	else
		output = ft_strjoin(msg, strerror(n));
	write(2, output, ft_strlen(output));
	write(2, "\n", 1);
	exit(n);
}

void	free_box(char **box)
{
	int	i;

	i = 0;
	while (box && box[i])
		free(box[i++]);
	free(box);
}

char	**ft_cutstr(char *s)
{
	int		i;
	char	**rtn;

	i = 0;
	rtn = (char **)malloc(sizeof(char *) * 3);
	if (!rtn)
		return (NULL);
	rtn[2] = NULL;
	while (s[i] && s[i] != ' ')
		i++;
	rtn[0] = ft_strndup(s, i);
	if (!s[i] || !s[i + 1])
	{
		rtn[1] = NULL;
		return (rtn);
	}
	i++;
	rtn[1] = ft_strndup(s + i, ft_strlen(s + i));
	return (rtn);
}

char	*ft_strndup(char *s, int n)
{
	char	*rtn;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (n + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		rtn[i] = s[i];
		i++;
	}
	while (i <= n)
		rtn[i++] = 0;
	return (rtn);
}
