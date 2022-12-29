/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:41:27 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/29 14:22:53 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

// char	**build_cmd_box(char **box ,int n);
// char	*erase_quote(char *s, char c, int n);
// char	**ft_cutstr(char *s);
// char	*ft_strndup(char *s, int n);

// int	main(int argc, char **argv)
// {
// 	char s[] = "hello'world'thankyou";
// 	char **box;
// 	int i;

// 	i = 0;
// 	box = ft_cutstr(s);
// 	box = build_cmd_box(box, 6);
// 	while (box[i])
// 	{
// 		printf("%s\n", box[i++]);
// 	}
// }

int	main(int argc, char**argv, char** envp)
{
	int	i;
	char **my_argv;

	my_argv = parse_quote(ft_cutstr(argv[1]));
	i = 0;
	while (my_argv[i])
	{
		printf("argc : %d, argv : %s\n", i, my_argv[i]);
		i++;
	}
	//execve(argv[1], &argv[1], envp);
}
