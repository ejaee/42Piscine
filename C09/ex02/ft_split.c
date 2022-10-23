/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:34:19 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/16 18:30:59 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *str, char *charset)
{
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str && !is_charset(str, charset))
		{
			cnt++;
			while (*str && !is_charset(str, charset))
				str++;
		}
		str++;
	}
	return (cnt);
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size)
		dest[idx] = src[idx];
	dest[idx] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**input;
	int		cnt_word;
	char	*from;
	int		idx;

	cnt_word = ft_count_word(str, charset);
	input = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!input)
		return (0);
	idx = -1;
	while (++idx < cnt_word)
	{
		if (*str && !is_charset(str, charset))
		{	
			from = str;
			while (*str && !is_charset(str, charset))
				str++;
			input[idx] = (char *)malloc(str - from + 1);
			ft_strncpy(input[idx], from, str - from);
		}
		str++;
	}
	input[cnt_word] = 0;
	return (input);
}
/*
#include <stdio.h>
int main()
{
	char *str = "minsoo ejae wanda jackson";
	char *charset = " ";
	char **dest = ft_split(str, charset);
	int	idx;

	idx = -1;
	while (dest [++idx])
		printf("%s\n", dest[idx]);

	return 0;
}
*/
