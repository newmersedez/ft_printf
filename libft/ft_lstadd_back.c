#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp_ptr = *lst;
		while (temp_ptr->next)
			temp_ptr = temp_ptr->next;
		temp_ptr->next = new;
	}
}
