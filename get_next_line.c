/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:56:16 by adstan            #+#    #+#             */
/*   Updated: 2018/01/09 16:19:24 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	dudu(int i, t_list *start, char **line)
{
	(*line) = (char*)malloc(sizeof(char) * (i + 1));
	(*line)[i] = 0;
	i = 0;
	while (start)
	{
		(*line)[i++] = start->content[0];
		start = start->next;
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int		i;
	int		ret;
	char	buff;
	t_list	*list;
	t_list	*start;

	i = 0;
	start = NULL;
	if ((ret = read(fd, &buff, 1)) < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!ret)
		return (0);
	if (buff != '\n')
	{
		start = ft_lstnew(&buff, 1);
		list = start;
		i++;
		while ((ret = read(fd, &buff, 1)) > 0 && buff != '\n')
		{
			list->next = ft_lstnew(&buff, 1);
			list = list->next;
			i++;
		}
	}
	return (dudu(i, start, line));
}
