/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:07:29 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/20 00:53:16 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		idx;
	int		jdx;
	char	*temp;

	idx = 0;
	while (tab[idx])
	{
		jdx = idx + 1;
		while (tab[jdx])
		{
			if ((*cmp)(tab[idx], tab[jdx]) > 0)
			{
				temp = tab[idx];
				tab[idx] = tab[jdx];
				tab[jdx] = temp;
			}
			jdx++;
		}
		idx++;
	}
}
/*
int	ft_cmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
#include <unistd.h>

void	ft_putstr(char *s1)
{
	while (*s1)
		write (1, s1++, 1);
}

int	main()
{
	char *arr[] = {"dsfe", "adsfsd", "bsdf", "cvfsd", "efsd", 0};

	ft_advanced_sort_string_tab(arr, ft_cmp);
	int idx = -1;
	while (arr[++idx])
	{
		ft_putstr(arr[idx]);
		write (1, " ", 1);
	}
}
*/
