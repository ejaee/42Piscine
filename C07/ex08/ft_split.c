/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:49:26 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/05 16:25:09 by choiejae         ###   ########.fr       */
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
	int	flag;

	flag = 1;
	cnt = 0;
	while (*str)
	{
		while (is_charset(*str, charset))
		{
			flag++;
			str++;
		}
		if (!*str)
			break;
		if (flag)
		{
			cnt++;
			flag = 0;
		}
		str++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int idx, int len)
{
	int	jdx;

	jdx = -1;
	while (++jdx < len)
		dest[jdx] = src[idx + jdx];
	dest[jdx] = '\0';
}

int	get_length(char *str, char *charset, int idx)
{
	int	cnt;

	cnt = 0;
	while (str[idx + cnt])
	{
		if (is_charset(str[idx + cnt], charset))
			break;
		cnt++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int	i1;
	int i2;
	int	jdx;
	int	word;
	int	len;

	word = count_word(str, charset);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (0);
	idx = 0;
	while (str[idx])
	{
		i2 = 0;
		arr[i1] = malloc(sizeof(char) * len[i1])
		while (is_charset(*str, charset))
			str++;
		if (!*str)
			break;
		while ()
		len = get_length(str, charset, idx);
		res[jdx] = malloc(sizeof(char) * (len + 1));
		ft_strncpy(res[jdx], str, idx, len);
		idx += len;
	}
	res[jdx] = 0;
	return (res);
}

#include <stdio.h>
int main()
{
	char *str = "one two three four five";
	char **split;
	int	idx;

	split = ft_split(str, " ");
	idx = -1;
	while (split[++idx])
		printf("%s\n", split[idx]);
	return 0;
}
