/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:36:36 by malord            #+#    #+#             */
/*   Updated: 2022/04/19 08:31:57 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if the value of parameter int n is in the ASCII table
int	ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
		return (1);
	return (0);
}
