/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:47:11 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/29 06:29:58 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>

char	*render(char *save);
char	*save_treat(char *save);
int		get_next_line(int fd, char **line);
void	saver(char *save, char *box, int c);

#endif
