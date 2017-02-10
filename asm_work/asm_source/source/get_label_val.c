#include "common.h"

static int	get_cur_inst(t_info *info, t_glob)
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

int	get_label_val(t_info *info, t_glob glob)
{
	int	label;
	int	line;
	t_list	*lst_lab;
	char	*str;
	
	lst_lab = glob.label;
	line = get_cur_inst(info, glob);
	label = 0;
	str = info->param[i];
	while (lst_lab && )
	{
		label++;
		lst_lab = lst_lab->next;
	}
	if (!lst_tab)
		;
	return (line - label);
}
