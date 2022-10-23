/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:54:54 by choiejae          #+#    #+#             */
/*   Updated: 2022/04/08 13:21:31 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long ul)
{
	char	*hex;
	char	stack[17];
	int	idx;

	hex = "0123456789abcdef";
	idx = 0;
	while (idx < 16)
	{
		stack[idx++] = hex[ul % 16];
		ul /= 16;
	}
	idx = 15;
	while (idx >= 0)
		write(1, &stack[idx--], 1);
}

void	print_hex(char *p, int i, int size)
{
	char *hex;
	int	j;

	hex = "0123456789abcdef";
	j = 0;
	while (j < 16 && i + j < size)
	{
		write(1 ,&(hex[p[i + j] / 16]), 1);
		write(1 ,&(hex[p[i + j] % 16]), 1);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
}

void	print_char(char *p, int i, int size)
{
	int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (32 <= p[i + j] && p[i + j] <= 126)
			write(1, &p[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	ul;
	unsigned int	i;
	char	*p;

	ul = (unsigned long)addr;
	p = (char *)addr;
	i = 0;
	while (i < size)
	{
		print_addr(ul);
		write(1, ": ", 2);
		print_hex(p, i, size);
		print_char(p, i, size);
		write(1, "\n", 1);
		i += 16;
		ul += 16;
	}
	return (addr);
}

int ft_strlen(char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int main(void)
{
    char	*addr;
	addr = "Bonjour les aminches\t\n\tc  est f u\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
    ft_print_memory(addr, ft_strlen(addr) + 1);
	return (0);
}
