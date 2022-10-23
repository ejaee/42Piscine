/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:31:32 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/14 13:34:41 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	total_strlen(int size, char **strs, char *sep)
{
	int		idx;
	int		sum_len;

	idx = 0;
	sum_len = 0;
	while (idx < size)
	{
		sum_len += ft_strlen(strs[idx]);
		idx++;
	}
	sum_len += (size - 1) * ft_strlen(sep) + 1;
	return (sum_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		cnt;
	int		idx;

	cnt = 0;
	while (dest[cnt])
		cnt++;
	idx = 0;
	while (src[idx])
		dest[cnt++] = src[idx++];
	dest[cnt] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*buf;
	int		idx;

	if (size <= 0)
	{
		buf = malloc(sizeof(char) * 1);
		return (buf);
	}
	buf = malloc(sizeof(char) * total_strlen(size, strs, sep));
	if (!buf)
		return (0);
	idx = 0;
	while (idx < size)
	{
		ft_strcat(buf, strs[idx]);
		if (idx < size - 1)
			ft_strcat(buf, sep);
		idx ++;
	}
	return (buf);
}
/*
#include <unistd.h>
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	char	**strs;
	char	*separator;
	char	*result;
	int	size;
	int idx;
	idx = -1;
	size = 3;
	strs = (char **)malloc(size * sizeof(char *));
	while (++idx < size)
	{
		strs[idx] = (char *)malloc(sizeof(char) * 5 + 1);
		strs[idx] = "hello";
	}
	separator = " ";
	result = ft_strjoin(size, strs, separator);
	ft_putstr(result);
	free(result);
}
*/
