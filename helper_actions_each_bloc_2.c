/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_actions_each_bloc_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:28:56 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/30 01:50:32 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "twenty_one.h"

void		init_int_table(int *table, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		table[i] = -1;
}

void		do_all_pipe(int *pipe_fd, int nb_pipe)
{
	int		i;

	i = 0;
	while (++i <= nb_pipe)
	{
		if (pipe(pipe_fd) < 0)
			ft_putendl_fd("pipe failed in  do all pipe", 2);
		pipe_fd = pipe_fd + 2;
	}
}

int			pro_is_buildin_no_pipe(t_word *list, char ***env, t_sh *table)
{
	char		**pro_args;
	t_save_fd	*recover;

	recover = NULL;
	pro_args = NULL;
	recover = fd_restorage(list, recover);
	pro_args = my_here_doc_word_init_pro_args(list);
	all_case_redirection(list);
	do_build(pro_args, env, table);
	recover_fd(recover);
	free_saver_fd(recover);
	if (pro_args)
		free(pro_args);
	return (0);
}
