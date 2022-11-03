/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:20:13 by jlima             #+#    #+#             */
/*   Updated: 2022/06/10 10:11:17 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*paste_remaining_buffer(char *remaining_buffer, char *str)
{
	int		i;
	char	*str_1;
	int		len;

	len = ft_strlen_gnl(remaining_buffer);
	str_1 = malloc(len + 1);
	if (!(str_1))
		return (NULL);
	str_1[len] = '\0';
	i = 0;
	while (remaining_buffer[i] != '\0')
	{
		str_1[i] = remaining_buffer[i];
		i++;
	}
	free(str);
	return (str_1);
}

char	*update_buffer(char *buffer, char *str, int value)
{
	unsigned int	j;
	unsigned int	i;
	char			*updated_buffer;

	buffer[value] = '\0';
	if (ft_strchr_gnl(str, '\n'))
	{
		updated_buffer = ((char *)malloc(ft_strlen_gnl(buffer) + (ft_strlen_gnl(str))
					+ 1));
		j = 0;
		i = 0;
		while (str[j] != '\0')
			updated_buffer[i++] = str[j++];
		j = 0;
		while (buffer[j] != '\0')
			updated_buffer[i++] = buffer[j++];
		updated_buffer[i] = '\0';
		free(buffer);
		return (updated_buffer);
	}
	return (buffer);
}

char	*get_remaining_buffer(char *buffer, char *remaining_buffer)
{
	unsigned int	j;
	unsigned int	i;
	char			*remain_buffer;

	if (ft_strchr_gnl(buffer, '\n'))
	{
		j = 0;
		i = 0;
		while (buffer[j] != '\n')
			j++;
		remain_buffer = (char *)malloc((ft_strlen_gnl(buffer) - j) + 1);
		j++;
		while (buffer[j] != '\0')
			remain_buffer[i++] = buffer[j++];
		remain_buffer[i] = '\0';
		free(remaining_buffer);
		return (remain_buffer);
	}
	free(remaining_buffer);
	return (NULL);
}

char	*ft_strjoin_gnl(char *str, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(ft_strlen_gnl(str) + BUFFER_SIZE + 1);
	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		new_str[j++] = str[i++];
	if (str[i] != '\n')
	{
		j = 0;
		while (buffer[j] != '\n' && buffer[j] != '\0')
			new_str[i++] = buffer[j++];
		if (buffer[j] == '\0' && j != 0)
		{
			free(str);
			new_str[i] = '\0';
			return (new_str);
		}
	}
	free(str);
	new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static char	*remain_buffer[4096];
	int			value;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_calloc_gnl(1, 1);
	len = 0;
	while (str[len] != '\n')
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		value = read(fd, buffer, BUFFER_SIZE);
		if (check_value(value, str, buffer) == 0 || !buffer)
			return (NULL);
		if (remain_buffer[fd] != NULL)
			str = paste_remaining_buffer(remain_buffer[fd], str);
		buffer = update_buffer(buffer, str, value);
		remain_buffer[fd] = get_remaining_buffer(buffer, remain_buffer[fd]);
		str = (ft_strjoin_gnl(str, buffer));
		free(buffer);
		len = ft_strlen_gnl(str) - 1;
	}
	return (check_exit(str, remain_buffer[fd], value));
}
