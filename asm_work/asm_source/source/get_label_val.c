#include "common.h"

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
	
	lst_lab = glob.label;
	line = get_cur_inst(info, glob);
	label = 0;
	str = info->param[i];
	while (*str != ':')
		str++;
	str++;
	//ft_putendl(str);
	while (lst_lab && ft_strncmp(str, ((t_label*)(lst_lab->content))->str,
		ft_strlen(str)))
	{
	//	ft_putendl(((t_label*)(lst_lab->content))->str);
		label++;
		lst_lab = lst_lab->next;
	}
	if (!lst_lab)
		error(BAD_LABEL_FORMAT);
	/*ft_putendl(((t_label*)(lst_lab->content))->str);
	ft_putnbr(line - label);
	ft_putstr("\n\n");*/
	return (line - label);
}
