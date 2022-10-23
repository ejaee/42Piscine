/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:35:42 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 18:17:07 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str ++;
		if (*str && !is_charset(*str, charset))
		{
			cnt++;
			while (*str && !is_charset(*str, charset))
				str ++;
		}
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	idx;

	idx = -1;
	while (src[++idx] && size--)
	{
		dest[idx] = src[idx];
	}
	dest[idx] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		cnt_word;
	char	**dest;
	char	*from;

	cnt_word = count_word(str, charset);
	dest = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!dest)
		return (0);
	idx = -1;
	while (++idx < cnt_word)
	{
		while (*str && is_charset(*str, charset))
			str++;
		from = str;
		while (*str && !is_charset(*str, charset))
			str ++;
		dest[idx] = (char *)malloc(str - from + 1);
		if (!dest[idx])
			return (0);
		ft_strncpy(dest[idx], from, str - from);
		str ++;
	}
	dest[cnt_word] = 0;
	return (dest);
}
/*
#include <stdio.h>
int main()
{
char	*arr = "Hello my name is e-jae";
char	*charset = " ";
char	**dest;
int		idx;

dest = ft_split(arr, charset);
idx = -1;
while (dest[++idx])
{
printf("%s\n", dest[idx]);
}
return (0);
}
 */
