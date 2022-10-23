/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:28:35 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 23:04:31 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		idx;
	int		jdx;
	char	*tmp;

	idx = 0;
	while (tab[idx])
	{
		jdx = idx + 1;
		while (tab[jdx])
		{
			if (ft_strcmp(tab[idx], tab[jdx]) > 0)
			{
				tmp = tab[idx];
				tab[idx] = tab[jdx];
				tab[jdx] = tmp;
			}
			jdx++;
		}
		idx++;
	}
}
