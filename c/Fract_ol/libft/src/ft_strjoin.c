/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:13:36 by jspezia           #+#    #+#             */
/*   Updated: 2014/01/04 20:00:53 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		ft_strcat(str, s3);
	}
	return (str);
}
