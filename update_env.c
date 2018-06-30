/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:36:07 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/27 17:36:36 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "twenty_one.h"

void	update_shlvl(char ***env)
{
	char	**cp;
	int		level;
	char	*shlvl[4];
	char	*lv;

	cp = *env;
	level = 1;
	while (*cp && !(!ft_strncmp(*cp, "SHLVL", 5)))
		cp++;
	if (*cp)
		level = ft_atoi(*cp + 6) + 1;
	lv = ft_itoa(level);
	shlvl[0] = "no real meaning here";
	shlvl[1] = "SHLVL";
	shlvl[2] = lv;
	shlvl[3] = NULL;
	set_env(shlvl, env);
	free(lv);
}

void	update_lastapp(char *lastcmd, char ***env)
{
	char *lastapp[4];

	lastapp[0] = "no real meaning here";
	lastapp[1] = "_";
	lastapp[2] = lastcmd;
	lastapp[3] = NULL;
	set_env(lastapp, env);
}
