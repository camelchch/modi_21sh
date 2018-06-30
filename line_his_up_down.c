/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_his_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:49:10 by saxiao            #+#    #+#             */
/*   Updated: 2018/06/28 23:44:01 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one.h"

static void		for_his_up(t_line *line)
{
	if (!line->last_his->pre)
		line->his_mostup = 1;
	if (line->up_indown && !line->last_his->next)
		line->one_his = 1;
}

int				history_up(t_line *line)
{
	int		i;

	i = -1;
	if (line->buf_len)
		delete_all(line);
	if (line->last_his)
	{
		if (!line->his_mostdown && line->last_his->pre)
			line->last_his = (line->last_his)->pre;
		if (!line->his_mostup)
		{
			while (line->last_his->his[++i])
			{
				put_a_key(line, line->last_his->his[i]);
				line->buf[i] = line->last_his->his[i];
			}
		}
		if (line->his_mostup == 1)
			line->up_indown = 1;
		if (!line->last_his->next)
			line->his_mostdown = 0;
		for_his_up(line);
	}
	return (0);
}

static void		for_his_down(t_line *line)
{
	if (!line->last_his->next)
		line->his_mostdown = 0;
	if (!line->last_his->pre)
		line->his_mostup = 1;
}

int				history_down(t_line *line)
{
	int		i;

	i = -1;
	if (line->buf_len)
		delete_all(line);
	if (line->last_his && !line->last_his->next && !line->one_his)
		line->his_mostup = 0;
	if (line->last_his && (line->last_his->next || line->one_his))
	{
		if (!line->up_indown && (line->last_his)->next)
			line->last_his = (line->last_his)->next;
		while (line->last_his->his[++i])
		{
			put_a_key(line, line->last_his->his[i]);
			line->buf[i] = line->last_his->his[i];
		}
		line->his_mostup = 0;
		line->up_indown = 0;
		for_his_down(line);
		line->one_his = 0;
	}
	else if (line->last_his && !line->last_his->next)
		line->his_mostdown = 1;
	return (0);
}
