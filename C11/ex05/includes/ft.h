/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:31:28 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/19 18:28:54 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_op(int a, char op, int b);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_sum(int a, int b);
void	ft_minus(int a, int b);
void	ft_multi(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);

#endif
