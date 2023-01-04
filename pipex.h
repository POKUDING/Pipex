/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:38 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/04 15:59:31 by junhyupa         ###   ########.fr       */
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

char	**build_argv_box(char **box, char *s);
char	**join_argv(char **argv, char *new);
char	**parse_argv(char *cmd);
char	**cpy_argv_box(char **box, char *s);

char	*ft_strndup(char *s, int n);
char	*find_path(char *cmd, char **envp);
void	executer(char *cmd, char **envp);

char	**ft_cutstr(char *s);
void	error_control(char *msg, char *msg2, int n);
void	free_box(char **box);

char	*ft_strndup(char *s, int n);
void	parents_process(char **argv, char **envp, int *fd);
#endif
