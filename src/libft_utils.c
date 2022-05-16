/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:51 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 13:30:06 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atof(char *s)
{
	double	sign;
	double	n;
	double	i;

	sign = 1;
	n = 0;
	i = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
	{
		n = n * 10 + *s - '0';
		s++;
	}
	if (*s == '.')
	{
		while (ft_isdigit(*++s))
		{
			i *= 0.1;
			n += (*s - '0') * i;
		}
	}
	return (n * sign);
}

int	ft_strcmp_f(const char *s1, const char *s2)
{
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
