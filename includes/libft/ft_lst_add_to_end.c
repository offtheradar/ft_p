/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_to_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:57:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/07 18:46:36 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_to_end(t_list *new_l, t_list **lst)
{
	t_list *curr;

	if (!new_l || !lst)
		return ;
	if (!*lst)
		*lst = new_l;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new_l;
	}
}
