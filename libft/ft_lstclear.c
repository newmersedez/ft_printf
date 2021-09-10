#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_ptr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		temp_ptr = *lst;
		*lst = (*lst)->next;
		del(temp_ptr->content);
		free(temp_ptr);
	}
}
