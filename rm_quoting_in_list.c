/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quoting_in_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:19:01 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/29 22:28:20 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one.h"

static int	type_can_hv_quote(t_word *list)
{
	return (list->type == PROGRAM || list->type == ARG || list->type == FILES);
	return (0);
}

void		change_part_str(char *ori, int start, int end, char *change)
{
	char	after[MAX_BUF];

	ft_bzero(after, MAX_BUF);
	ft_strcpy(after, ori + end + 1);
	ft_bzero(ori + start, MAX_BUF - start);
	ft_strcat(ori, change);
	ft_strcat(ori, after);
}

void		dollor_sign(t_helper *help, char *cp, char *vari)
{
	help->j = help->i + 1;
	help->k = 0;
	while (cp[help->j] && cp[help->j] != '"' && cp[help->j] != '$')
		vari[(help->k)++] = cp[(help->j)++];
}

void		remove_quoting_list(t_word *list, char **env)
{
	while (list)
	{
		if (type_can_hv_quote(list))
		{
			remove_quoting_word(list->word, env);
			if (list->type == PROGRAM && is_buildin(list->word))
				list->type = BUIDIN;
		}
		list = list->next;
	}
}

int			remove_quoting_bloc(t_word *list, char **env)
{
	int		find_bloc;

	find_bloc = 0;
	while (list && !find_bloc)
	{
		if (type_can_hv_quote(list))
		{
			if (remove_quoting_word(list->word, env))
				return (1);
			if (list->type == PROGRAM && is_buildin(list->word))
				list->type = BUIDIN;
		}
		if (!list->next || is_logic(list->next->type) || \
				list->next->type == SEMI_DOT)
			find_bloc = 1;
		else
			list = list->next;
	}
	return (0);
}
