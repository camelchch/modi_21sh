/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:33:40 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/19 19:33:41 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *c1, char *c2)
{
	char tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
