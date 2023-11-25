/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:23:29 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/25 06:47:15 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
/*#include <fcntl.h>
int main ()
{
	int fd;
	fd = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC , 777);

	ft_putchar_fd('A',fd);
}*/
