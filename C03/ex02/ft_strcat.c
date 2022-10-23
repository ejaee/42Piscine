/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:22:39 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/09 08:22:55 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx_d;
	int	idx_s;

	idx_d = 0;
	idx_s = 0;
	while (dest[idx_d])
	{
		idx_d++;
	}
	while (src[idx_s])
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	return (dest);
}
