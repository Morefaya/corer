#include "common.h"
#include "functions.h"

void	write_reg(int fd, t_info *info)
{
	int	tmp;
	char	*reg;

	reg = *info->param;
	reg++;
	tmp = 0;
	tmp = ft_atoi(reg);
	write(fd, (char*)&tmp, T_REG);
}

void	write_dir(int fd, int i, t_info *info, t_glob glob)
{
	int	tmp;
	char	opcode;
	
	(void)glob;
	(void)info;
	opcode = info->opcode;
	if (opcode == ZJUMP || opcode == LDI || opcode == STI \
		|| opcode == FORK || opcode == LLDI || opcode == LFORK)
	{
		if (!ft_strchr(*info->param, (int)':'))
			tmp = ft_atoi(info->param[i]);
		else
			tmp = 0; //get_label_val(info, glob);
		write(fd, (char*)&tmp, T_DIR);
	}
	else
	{
		if (!ft_strchr(*info->param, (int)':'))
			tmp = ft_atoi(info->param[i]);
		else
			tmp = 0;//get_label_val(info, glob);
		write(fd, (char*)&tmp, T_IND);
	}
}

void	write_ind(int fd, int i, t_info *info, t_glob glob)
{
	int	tmp;
	(void)glob;
	(void)info;

	if (!ft_strchr(*info->param, (int)':'))
		tmp = ft_atoi(info->param[i]);
	else
		tmp = 0;//get_label_val(info, glob);
	write(fd, (char*)&tmp, T_IND);
}

static void	w_param(int fd, t_info *info, t_glob glob)
{
	char	**param;
	int	i;
	char	opcode;

	param = info->param;
	i = 0;
	opcode = info->opcode;
	while (param && *param)
	{
		if (is_reg(*param))
			write_reg(fd, info);
		else if (is_direct(*param))
			write_dir(fd, i, info, glob);
		else if (is_ind(*param))
			write_ind(fd, i, info, glob);
		/*else
		{
			ft_putstr("PWOBLEM type arg: ");
			ft_putendl(*param);
		}*/
		i++;
		param++;
	}
}

static void	deal_param(int fd, t_info *info, t_glob glob)
{
	t_op	op[17];
	char	*opcode;
	char	*ocp;

	opcode = &info->opcode;
	ocp = (char*)&info->ocp;
	init_op_table(op);
	write(fd, opcode, 1);
	if (*opcode != LIVE && *opcode != ZJUMP && *opcode != FORK)
		write(fd, ocp, 1);
	w_param(fd, info, glob);
	free_op_table(op);
}

void		write_param(int fd, t_glob glob)
{
	t_info	*info;

	info = glob.list;
	while (info)
	{
		deal_param(fd, info, glob);
		info = info->next;
	}
}
