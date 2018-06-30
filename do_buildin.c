/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_buildin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:29:29 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/28 23:29:31 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "twenty_one.h"

int			is_buildin(char *app)
{
	return (!strcmp(app, "echo") || !strcmp(app, "cd") ||\
			!strcmp(app, "setenv") || !strcmp(app, "unsetenv") ||\
			!strcmp(app, "env") || !strcmp(app, "exit"));
}

static void	echo(char **paras)
{
	int		ct;

	ct = nb_str(paras);
	paras++;
	while (*paras)
	{
		ft_printf("%s", *paras++);
		if (ct-- > 2)
			ft_printf(" ");
		else
			ft_printf("\n");
	}
}

void		ft_exit(char ***env, t_sh *table)
{
	free_sh_table(table, 100);
	ft_freestrstr(*env);
	exit(0);
}

void		replace_home_cd(char *cp, char *home)
{
	int		i;
	char	temp[PATH_MAX + 1];

	ft_bzero(temp, PATH_MAX + 1);
	i = 0;
	while (cp[i] && cp[i] != '~')
		i++;
	ft_strcpy(temp, cp + i + 1);
	ft_bzero(cp + i, PATH_MAX + 1 - i);
	ft_strcpy(cp + i, home);
	ft_strcat(cp, temp);
}

void		do_build(char **paras, char ***env, t_sh *table)
{
	char	**all_path;

	all_path = NULL;
	update_lastapp(*paras, env);
	if (!ft_strcmp(*paras, "cd"))
		cd(paras, env);
	else if (!ft_strcmp(*paras, "echo"))
		echo(paras);
	else if (!ft_strcmp(*paras, "setenv") || !ft_strcmp(*paras, "unsetenv"))
	{
		if (!ft_strcmp(*paras, "unsetenv"))
			*env = unset_env(paras, *env);
		else
			set_env(paras, env);
		if (*(paras + 1) && !ft_strcmp(*(paras + 1), "PATH"))
		{
			all_path = path(*env);
			init_shtable(table, all_path);
			ft_freestrstr(all_path);
		}
	}
	else if (!ft_strcmp(*paras, "env"))
		put_env(*env, paras, table);
	else if (!ft_strcmp(*paras, "exit"))
		ft_exit(env, table);
}
