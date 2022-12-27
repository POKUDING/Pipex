/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:38 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/27 15:37:19 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>

# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

//del;
void	print_args(char **argv);

char	**build_cmd_box(char **box ,int n);
char	*ft_strndup(char *s, int n);
char	*find_path(char *cmd, char **envp);
void	executer(char *cmd, char **envp);

char	**ft_cutstr(char *s);
void	error_control(char *msg);
void	free_box(char **box);

char	*ft_strndup(char *s, int n);
void	parents_process(char **argv, char **envp, int *fd);
#endif
