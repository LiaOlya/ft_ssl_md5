/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:35:31 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/20 15:35:32 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MD5_H
# define __MD5_H

# include "libft/libft.h"
# include <fcntl.h>
#include <stdio.h>

#include <strings.h>

typedef	struct	s_files
{
	int				fd;
	struct s_files	*next;
}				t_files;

typedef struct	s_sha
{
	unsigned int	ma;
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	s0;
	unsigned int	t2;
	unsigned int	t1;
}				t_sha;

typedef struct	s_fl
{
	t_files	*f;
	int		q;
	int		r;
	int		s;
}				t_fl;

typedef struct	s_f
{
	int		argc;
	t_list	*files;
	t_list	*err;
	char	*str;
}				t_f;

typedef struct	s_read
{
	int				*fl;
	unsigned char	str[129];
	int				n;
	int				*e_k;
	t_list			*ech;
}				t_read;


#endif
