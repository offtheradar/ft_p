/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 01:11:57 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/17 01:12:36 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstrn_fd(char const *s, int fd, unsigned int n)
{
        if (!s || !fd || !n)
                return ;
        while (*s && n)
        {
                ft_putchar_fd(*s, fd);
				n--;
                s++;
        }
}