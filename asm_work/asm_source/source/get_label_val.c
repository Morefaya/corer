#include "common.h"

static int	help(int line, int label, t_glob glob)
{
	int	i;
	t_info	*info;
	int	ret;

	if (line == label)
		return (0);
	i = 0;
	info = glob.list;
	ret = 0;
	while (info)
	{
		if (line < label && i > line && i <= label)
			ret += count_byte_inst(info);
		else if (line > label && i > label && i <= line)
			ret += count_byte_inst(info);	
		/*if ((i > line && i < label) || (i > label && i < line))
			ret += count_byte_inst(info);*/
		i++;
		info = info->next;
	}
	ft_putstr("value: ");
	ft_putnbr(ret);
	ft_putendl("$");
	if (line > label)
		return (-1 * ret);
	else
		return (ret);
}

static int	get_cur_inst(t_info *info, t_glob glob)
{
	int	cur;
	t_info	*tmp;

	cur = 0;
	tmp = glob.list;
	while (tmp && tmp != info)
	{
		cur++;
		tmp = tmp->next;
	}
	return (cur);
}

int	get_label_val(t_info *info, t_glob glob, int i)
{
	int	label;
	int	line;
	t_list	*lst_lab;
	char	*str;

	ft_putchar('\n');;	
	lst_lab = glob.label;
	line = get_cur_inst(info, glob);
	label = 0;
	str = info->param[i];
	while (str && *str && *str != ':')
		str++;
	str++;
	/*ft_putstr("search label: ");
	ft_putendl(str);
	ft_putendl(((t_label*)(lst_lab->content))->str);*/
	while (lst_lab && ft_strncmp(str, ((t_label*)(lst_lab->content))->str,
		ft_strlen(str)))
	{
		ft_putendl(((t_label*)(lst_lab->content))->str);
		label++;
		lst_lab = lst_lab->next;
	}
	if (!lst_lab)
		error(BAD_LABEL_FORMAT);
	label = ((t_label*)(lst_lab->content))->n_inst;
	ft_putendl(((t_label*)(lst_lab->content))->str);
	ft_putnbr(line - label);
	ft_putstr("\n\n");
	ft_putstr("line: ");
	ft_putnbr(line);
	ft_putchar('\n');
	ft_putstr("label: ");
	ft_putnbr(label);
	ft_putendl("\n");
	return (help(line, label, glob));
}
