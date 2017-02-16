/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudra <hboudra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:07:44 by hboudra           #+#    #+#             */
/*   Updated: 2017/02/13 22:05:36 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "libft.h"
#include "functions.h"

/*
** Fonction de calcule de l'ocp, bien verifier que les parametres soient
** valident et que le char ** ne fasse pas plus de 3
*/

static void	check_ocp(t_info *info, int ocp)
{
	int	i;
	int	j;
	char	op;

	i = 0;
	while (info->param[i])
	{
		j = 0;
		op = (char)g_op_tab[(int)info->opcode - 1].arg_value[i];
		while (j++ < 3 - i)
			op <<= 2;
		if (!(op & ocp))
			error(BAD_ARGUMENT);
		i++;
	}
}

char	ocp_calc(t_info *info)
{
	char	ocp;
	int	i;

	ocp = 0;
	i = 0;
	while (info->param && info->param[i])
	{
		if (i > 2)
			return (0);
		if (is_reg(info->param[i]))
			ocp |= 0x01;
		else if (is_direct(info->param[i]))
			ocp |= 0x02;
		else if (is_ind(info->param[i]))
			ocp |= 0x03;
		ocp <<= 2;
		i++;
	}
	if (i != (int)g_op_tab[(int)info->opcode - 1].nb_arg)
		error(BAD_NUMBER_PARAM);
	while (i++ < 3)
		ocp <<= 2;
	check_ocp(info, ocp);
	return (ocp);
}
