/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:53:07 by rabougue          #+#    #+#             */
/*   Updated: 2017/01/13 14:54:23 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_cmt(char *line)
{
	int	blank;

	blank = skip_blank(line);
	if (line[blank] == COMMENT_CHAR ||
		line[blank] == '\0' ||
		line[blank] == COMMENT_CHAR_CROMA)
		return (true);
	return (false);
}

int		skip_blank(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) == true)
		++i;
	return (i);
}

// remplace les series de tab et de space par UN unique tab ou UN unique space renvoie la string correspondante

char	*clear_line(char *str)
{
	;
}
