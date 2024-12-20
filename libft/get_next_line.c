/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:04:20 by frey-gal          #+#    #+#             */
/*   Updated: 2024/12/13 18:45:07 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*cut(char *mem, int x)
{
	char	*tmp;

	tmp = duplen((mem + x), length(mem, '\0'));
	free(mem);
	return (tmp);
}

char	*free_all(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*butter(char *stash, char *buf)
{
	char	*tmp;

	free(buf);
	if (!find_nl(stash))
		tmp = duplen(stash, length(stash, '\0'));
	else
		tmp = duplen(stash, length(stash, '\n') + 1);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			b_read;
	char		*buf;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!find_nl(stash))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read < 0)
			return (free_all(stash, buf));
		buf[b_read] = '\0';
		if (b_read == 0)
			break ;
		stash = join_free(stash, buf);
		if (!stash)
			return (free_all(stash, buf));
	}
	next_line = butter(stash, buf);
	stash = cut(stash, length(next_line, '\0'));
	if ((!stash || !next_line) || (!stash && !b_read))
		return (free_all(stash, next_line));
	return (next_line);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int fd = open(av[1], O_RDWR);
	char *str = get_next_line(fd);
	//int	i = 0;
	while (str)
	{
		//printf("____\n%d iteration\n____\n%s", i++, str);
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}*/
