/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:41:27 by junhyupa          #+#    #+#             */
/*   Updated: 2022/12/27 16:25:33 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

	i = 0;
	while (i < argc)
	{
		printf("argc : %d, argv : %s\n", i, argv[i]);
		i++;
	}
	//execve(argv[1], &argv[1], envp);
}
