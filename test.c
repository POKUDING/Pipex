/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:41:27 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/31 13:52:22 by junhyupa         ###   ########.fr       */
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

	if (argc < 2)
		return (0);
	my_argv = parse_argv(argv[1]);
	i = 0;
	printf ("%s\n",argv[1]);
	while (my_argv[i])
	{
		printf("argc : %d, argv : %s\n", i, my_argv[i]);
		i++;
	}
	free_box (my_argv);
}

// int main(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while(argv[i])
// 		printf("%s\n",argv[i++]);
// 	return (0);
// }
