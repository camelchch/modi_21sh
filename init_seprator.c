/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_seprator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:39:18 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/28 23:40:38 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one.h"

static void		less_and(char *line, int *index, t_word *add)
{
	if (*index + 2 < (int)ft_strlen(line) && line[*index + 2] == '-')
	{
		ft_strcpy(add->word, "<&-");
		add->type = LESSANDMINUS;
		*index = *index + 3;
	}
	else
	{
		ft_strcpy(add->word, "<&");
		add->type = LESSAND;
		*index = *index + 2;
	}
}

static t_word	*less_type(char *line, int *index)
{
	t_word		*add;

	add = malloc_add();
	if (*index + 1 < (int)ft_strlen(line) && line[*index + 1] == '<')
	{
		ft_strcpy(add->word, "<<");
		add->type = DLESS;
		*index = *index + 2;
	}
	else if (*index + 1 < (int)ft_strlen(line) && line[*index + 1] == '&')
		less_and(line, index, add);
	else
	{
		ft_strcpy(add->word, "<");
		add->type = LESS;
		*index = *index + 1;
	}
	return (add);
}

static void		great_and(char *line, int *index, t_word *add)
{
	if (*index + 2 < (int)ft_strlen(line) && line[*index + 2] == '-')
	{
		ft_strcpy(add->word, ">&-");
		add->type = GREATANDMINUS;
		*index = *index + 3;
	}
	else
	{
		ft_strcpy(add->word, ">&");
		add->type = GREATAND;
		*index = *index + 2;
	}
}

static t_word	*great_type(char *line, int *index)
{
	t_word		*add;

	add = malloc_add();
	if (*index + 1 < (int)ft_strlen(line) && line[*index + 1] == '>')
	{
		ft_strcpy(add->word, ">>");
		add->type = DGREAT;
		*index = *index + 2;
	}
	else if (*index + 1 < (int)ft_strlen(line) && line[*index + 1] == '&')
		great_and(line, index, add);
	else
	{
		ft_strcpy(add->word, ">");
		add->type = GREAT;
		*index = *index + 1;
	}
	return (add);
}

t_word			*init_seprator(char *line, int *index)
{
	if (line[*index] == '<')
		return (less_type(line, index));
	else if (line[*index] == '>')
		return (great_type(line, index));
	else if (line[*index] == '|')
		return (pipe_or_type(line, index));
	else if (line[*index] == '&')
		return (and_type(line, index));
	else if (line[*index] == ';')
		return (semidot_type(line, index));
	else if (line[*index] == ';')
		return (semidot_type(line, index));
	else if (line[*index] == ' ' || line[*index] == '\t')
		*index = *index + 1;
	return (NULL);
}
