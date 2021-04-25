/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:45:35 by dchonvil          #+#    #+#             */
/*   Updated: 2021/04/25 04:12:23 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_next_line(char *save)
{
	int	c;

	if (!save)
		return (0);
	c = 0;
	while (save[c] != '\0')
	{
		if (save[c] == '\n')
			return (1);
		c++;
	}
	return (0);
}

int		count_char(char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	*copy_mem(void *box, const void *src, int n)
{
	int	c;

	if (src == box)
		return (box);
	c = 0;
	if (src < box)
		while (n--)
			((char*)box)[n] = ((char*)src)[n];
	else
		while (c < n)
		{
			((char*)box)[c] = ((char*)src)[c];
			c++;
		}
	return (box);
}

char	*treatment(char *save, char *l)
{
	int		c;
	int		i;
	int		size;
	char	*box;

	if (!save && !l)
		return (NULL);
	c = count_char(save);
	i = count_char(l);
	size = c + i + 1;
	box = malloc(sizeof(char) * size);
	if (!box)
		return (NULL);
	copy_mem(box, save, c);
	copy_mem((box + c), l, i);
	box[size - 1] = '\0';
	free(save);
	return (box);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	char		*l;
	static char	*save[5000];

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(l = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	r = 1;
	while (r != 0 && check_next_line(save[fd]) == 0)
	{
		if ((r = read(fd, l, BUFFER_SIZE)) == -1)
		{
			free(l);
			return (-1);
		}
		l[r] = '\0';
		save[fd] = treatment(save[fd], l);
	}
	free(l);
	*line = render(save[fd]);
	save[fd] = save_treat(save[fd]);
	if (r == 0)
		return (0);
	return (1);
}
