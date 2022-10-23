/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:48 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 00:15:42 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		idx;

	hex = "0123456789abcdef";
	idx = -1;
	while (str[++idx])
	{
		if (32 <= str[idx] && str[idx] <= 126)
			write(1, &str[idx], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[(unsigned char)str[idx] / 16], 1);
			write(1, &hex[(unsigned char)str[idx] % 16], 1);
		}
	}
}
/*
int main()
{
	char text1[] = \
	"salut, comment tu vas ? \x24\x42\x28\n\t\x7f\x8e 
	42mots quarante-deux; cinquante+et+un";
	ft_putstr_non_printable(text1);
    char text2[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(text2);
	return (0);
}
*/
