/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:04:42 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 00:08:27 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		idx;
	int		cnt;

	idx = -1;
	cnt = 0;
	while (++idx < length)
	{
		if (f(tab[idx]))
			cnt++;
	}
	return (cnt);
}
