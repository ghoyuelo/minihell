/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:00:11 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/02/16 20:00:11 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_w_heredoc(t_stack *stack)
{
	t_stack	*tmp;
	char	*path;
	char	*txt;
	char	*limit;
	int		fd;

	tmp = stack;
	path = NULL;
	txt = NULL;
	limit = tmp->next->pipe.cmd;
	fd = open("./heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	while (1)
	{
		txt = readline("heredoc$> ");
		if (strcmp(txt, limit) == 0)
			break ;
		write(fd, txt, sizeof(char) * ft_strlen(txt));
		write(fd, "\n", 1);
	}
	close(fd);
	return (fd);
}

int	open_r_heredoc(t_stack *stack)
{
	t_stack	*tmp;
	char	*path;
	char	*txt;
	char	*limit;
	int		fd;

	tmp = stack;
	path = NULL;
	txt = NULL;
	limit = tmp->pipe.cmd;
	fd = open("./heredoc.txt", O_RDONLY, S_IRWXU);
	return (fd);
}
