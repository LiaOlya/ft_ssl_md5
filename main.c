/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:35:50 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/20 15:35:52 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_add_files(t_list **files, char *name)
{
	t_list		*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->content = ft_strdup(name);
	tmp->next = NULL;
	ft_lstadd(files, tmp);
}

int		ft_not_a_flag(char *name)
{
	int			i;
	const char	*flags[4] = {"-p", "-q", "-r", "-s"};
	int			cmp;

	i = 0;
	cmp = 0;
	while (i < 4)
	{
		if (ft_strcmp(name, flags[i++]) != 0)
			++cmp;
	}
	if (cmp >= 4)
		return (1);
	return (0);
}

char	*ft_err(char *str1, char *arg, char *str2, char *name)
{
	char	*tmp;
	int		l[2];
	int		i;

	l[0] = ft_strlen(arg);
	l[1] = ft_strlen(name);
	tmp = (char*)malloc(sizeof(char) * (27 + l[0] + l[1] + 8));
	i = 0;
	ft_strcpy(&(tmp[i]), str1);
	i += ft_strlen(str1);
	ft_strcpy(&(tmp[i]), arg);
	i += l[0];
	tmp[i++] = ':';
	tmp[i++] = ' ';	
	ft_strcpy(&(tmp[i]), name);
	i += l[1];
	ft_strcpy(&(tmp[i]), str2);
	i += ft_strlen(str2);
	tmp[i] ='\0';
	return (tmp);
}

void	ft_err_lst(char *arg, t_list **err)
{
	char	*tmp;
	int		len;
	int		i; 

	len = ft_strlen(arg);
	tmp = (char*)malloc(sizeof(char) * (len + 39));
	i = 0;
	ft_strcpy(&(tmp[i]), "ft_ssl: ");
	i += ft_strlen("ft_ssl: ");
	ft_strcpy(&tmp[i], arg);
	i += len;
	ft_strcpy(&tmp[i], ": -s: No such file or directory");
	ft_lstaddend(err, tmp);
}

void	ft_fl_wh(char *arg, const char *flags[], int **fl)
{
	int	i;

	i = 1;
	while (++i < 6)
	{
		if (ft_strcmp(arg, flags[i - 2]) == 0)
		{
			(*fl)[i - 1] = 1;
			break ;
		}
	}
}

void	ft_fl_h(t_f *fg, char *arg, int **fl, int *k)
{
	int		fd;
	char	*tmp;

	if (fg->argc && (fd = open(arg, O_RDONLY)) >= 0)
	{
		ft_add_files(&(fg->files), arg);
		(*fl)[(*k)++] = fd;
	}
	else if (fg->argc && ft_not_a_flag(arg))
	{
		tmp = ft_err("ft_ssl: ", fg->str, ": No such file or directory", arg);
		ft_lstaddend(&(fg->err), tmp);
	}
}

void	ft_flags(char **arg, int **fl, t_f *fg, unsigned char **s)
{
	const char	*flags[4] = {"-p", "-q", "-r", "-s"};
	int			i[2];
	int			k;

	i[0] = 1;
	k = 5;
	fg->str = arg[1];
	while (arg[++(i[0])])
	{
		ft_fl_wh(arg[i[0]], flags, fl);
		if ((*fl)[4] == 1 && *s == NULL)
		{
			*s = (unsigned char*)ft_strdup(arg[++(i[0])]);
			(*fl)[k++] = -2;
			++(i[0]);
		}
		else if (ft_strcmp(arg[i[0]], "-s") == 0 && (*fl)[4] == 1 && *s)
			ft_err_lst(arg[1], &(fg->err));
		if ((*fl)[1] == 1 && k == 5)
			(*fl)[k++] = 0;
		if (i[0] < fg->argc)
			ft_fl_h(fg, arg[i[0]], fl, &k);
	}
	if (k == 5 || (*fl)[1] == 1)
		(*fl)[0] = 1;
}

void	ft_error(char *argv)
{
	write(1, "ft_ssl: Error: '", 16);
	write(1, argv, ft_strlen(argv));
	write(1, "' is an invalid command.\n\nStandard commands:\n\n", 46);
	write(1, "Message Digest commands:\nmd5\nsha256\n\nCipher commands:\n", 54);
}

int		ft_r_h(t_read *r)
{
	int rd;

	rd = 0;
	if (r->fl[0] == 1)
	{
		while (r->e_k[0] > 0 && rd < 64)
		{
			r->e_k[0] = read(0, &(r->str)[rd], r->n - rd);
			if((r->e_k)[0] > 0)
				rd += (r->e_k)[0];
			if (r->fl[1] == 1 && (rd == 64 || ((r->e_k)[0] == 0 && rd < 64)))
				ft_lstaddend(&(r->ech), (char*)(r->str));
		}
	}
	else if (r->fl[(r->e_k)[1]] >= 0)
	{
		(r->e_k)[0] = read(r->fl[(r->e_k)[1]], r->str, r->n);
		rd = (r->e_k)[0];
	}	
	return (rd);
}

int		ft_read(t_read *r)
{
	int	rd;

	printf("ookok\n");
	if (r->fl[r->e_k[1]] == -3)
		++(r->e_k[1]);
	printf("ok\n");	
	rd = ft_r_h(r);
	if (r->e_k[1] >= 5 && r->fl[r->e_k[1]] >= 0 && (r->e_k[0] == 0 || rd < 64))
		++(r->e_k)[1];
	if (r->fl[(r->e_k)[1]] == -1 && !(r->fl[0] == 1 && r->e_k[0] != 0))
		r->e_k[1] = -1;
	r->str[rd] = '\0';
	return (rd);
}

void	ft_stroll(unsigned char *str, unsigned int (*w)[], int amm)
{
	int				j;
	int				i;
	int				k;
	unsigned int	num;
	unsigned char	tmp;

	i = -1;
	k = 0;
	num = 0;
	j = 0;
	while (++i <= amm)
	{
		tmp = str[i];
		num = num | (tmp << k);
		k += 8;
		if (i > 2 && (i + 1) % 4 == 0)
		{
			(*w)[j] = num;
			num = 0;
			++j;
		}
	}
}

unsigned int	ft_k(int i)
{
	unsigned int const k[64] = {0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B,
	 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
   0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
   0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
   0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
   0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
   0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
   0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
   0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2};

	return (k[i]);
}

void ft_init_list(t_f *f, int j, char *name, unsigned int const init[])
{
	t_list	*tmp;
	char	a[j];
	int		i;

	printf("33\n");
	ft_strcpy(a, name);
	i = j - 2;
	printf("44\n");
	while (i >= 0)
	{
		tmp = (t_list*)malloc(sizeof(t_list));
		tmp->content = ft_strsub(a, i, 1);
		tmp->content_size = init[i];
		tmp->next = NULL;
		ft_lstadd(&(f->files), tmp);
		--i;
	}
}

unsigned int	ft_t(int i)
{
	unsigned int const	t[64] = {0xd76aa478, 0xe8c7b756, 0x242070db,
	0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8,
	0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e,
	0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d,
	0x2441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 0xf4d50d87,
	0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942,
	0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60,
	0xbebfbc70, 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05, 0xd9d4d039,
	0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7,
	0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f,
	0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb,
	0xeb86d391};

	return (t[i]);
}

unsigned int ft_f(unsigned int a, unsigned int b, unsigned int c)
{
	return ((a & b) | (~a & c));
}

unsigned int ft_g(unsigned int a, unsigned int b, unsigned int c)
{
	return ((a & c) | (b & ~c));
}

unsigned int ft_h(unsigned int a, unsigned int b, unsigned int c)
{
	return (a ^ b ^ c);
}

unsigned int ft_i(unsigned int a, unsigned int b, unsigned int c)
{
	return (b ^ (a | ~c));
}

unsigned int ft_rotr(unsigned int a, unsigned int i)
{
	return ((a >> i) | (a << (32 - i)));
}

unsigned int ft_c_shift(unsigned int a, unsigned int i)
{
	return ((a << i) | (a >> (32 - i)));
}

void ft_r(unsigned int (*ac)[], unsigned int X, int s, int i)
{
	static unsigned int	(*func[4])(unsigned int, unsigned int,unsigned int) =
	 {ft_f, ft_g, ft_h, ft_i};
	int					j;

	j = i / 16;
	(*ac)[0] = (*ac)[1] + ft_c_shift(((*ac)[0] + func[j]((*ac)[1], (*ac)[2], 
	(*ac)[3]) + X + ft_t(i)), s);
}

int			ft_num_byte(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 255;
		++i;
	}
	return (i);
}

void ft_repl_w(t_list  **w)
{
	t_list	*t_lst;
	t_list	*tmp;
	t_list	*last;
	int		j;

	j = 0;
	t_lst = *w;
	while (j++ != 3)
		t_lst = t_lst->next;
    last = *w;
    tmp = *w;
    while(last->next != NULL)
    {
        tmp = last;
        last = last->next;
    }
    tmp->next = NULL;
	t_lst->next = NULL;
	ft_lstadd(w, t_lst);
}

void ft_lp(t_list *baf, unsigned int (*tbl)[])
{
	t_list	*head;
	int		p;

	head = baf;
	p = 0;
	while (head && p < 4)
	{
		(*tbl)[p++] = head->content_size;
		head = head->next;
	}
}

void ft_lp2(t_list **baf, unsigned int tbl[])
{
	t_list	*head;
	int		p;

	head = *baf;
	p = 0;
	while (head && p < 4)
	{
		head->content_size = tbl[p++];
		head = head->next;
	}
	ft_repl_w(baf);
}

void ft_bzero_int(int (*ar)[], unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		(*ar)[i++] = 0;
}

void ft_main_loop(unsigned int words[], t_list **baf)
{
	unsigned int	tbl[4];
	int				x[4];
	int const		s[4][4] = {{7, 12, 17, 22},
						 {5, 9, 14, 20}, 
						 {4, 11, 16, 23}, 
						 {6, 10, 15, 21}};
	int const		r[4][16] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
	14, 15}, {1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12}, {5, 8, 11,
	14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2}, {0, 7, 14, 5, 12, 3, 10, 1, 8,
	15, 6, 13, 4, 11, 2, 9}};

	ft_bzero(tbl, 4);
	ft_bzero_int(&x, 4);
	while (x[0] != 64 && x[1] != 4 && x[2] != 16)
	{
		ft_lp(*baf, &tbl);
		ft_r(&tbl, words[r[x[1]][x[2]++]], s[x[1]][x[3]++], x[0]++);
		ft_lp2(baf, tbl);
		if (x[3] == 4)
			x[3] = 0;
		if (x[0] % 16 == 0)
		{
			x[2] = 0;
			++x[1];
		}
	}
}

void ft_safe(unsigned int tmp[], t_list *baf)
{
	t_list	*t;
	int		i;
	
	i = 0;
	t = baf;
	while (baf && i < 4)
	{
		tmp[i++] = baf->content_size;
		baf = baf->next;
	}
	baf = t;
}

void ft_loop_call(t_list **baf, unsigned char str[])
{
	t_list			*repl;
	unsigned int	tmp[4];
	int				f;
	unsigned int	words[16];

	ft_stroll(str, &words, 64);
	ft_safe(tmp, *baf);
	ft_main_loop(words, baf);	
	repl = *baf;
	f = 0;
	while (repl && f < 4)
	{
		repl->content_size += tmp[f++];
		repl = repl->next;
	}
}

void ft_out(int **fl, t_list *files, int ix, t_list *ech)
{
	if (files && ix == 0 && (*fl)[3] == -1 && (*fl)[2] != 1 && (*fl)[0] != 1)
	{
		printf("%s) = ", (char*)((files)->content));
	}
	if (files && ix == 1 && (*fl)[3] == 1 && (*fl)[2] != 1 && (*fl)[0] != 1)
	{
		printf(" %s", (char*)((files)->content));
	}
	if ((*fl)[1] == 1 && ((*fl)[5] == 0 || (*fl)[0] == 1) && ix == 0)
	{
		while (ech)
		{
			printf("%s", (char*)(ech->content));
			ech = ech->next;
		}
		(*fl)[1] = 0;
	}
}

void ft_m(t_list **baf, unsigned char (*str)[129], int fl[], t_list *files, t_list *ech)
{
	t_list				*head;
	int					k;
	unsigned int const	init[4] = {0x67452301, 0xEFCDAB89, 0x98BADCFE,
	0x10325476};

	head = *baf;
	if (files && fl[3] == -1 && fl[2] != 1 && fl[0] != 1)
		printf("MD5 (");
	ft_out(&fl, files, 0, ech);
	
	while (head)
	{
		k = 0;
		while (k < 32)
		{
			printf("%.2x", (unsigned int)(((head->content_size) >> k) & 255));
			k += 8;
		}
		head = head->next;
	}
	ft_out(&fl, files, 1, ech);
	head = *baf;
	k = 0;
	while (k < 4 && head)
	{
		head->content_size = init[k++];
		head = head->next;
	}
	ft_bzero(*str, 129);
	
}

void ft_pad(int rd, unsigned char (*str)[129], int len)
{
	int	i;
	int	j;
	int	k;

	i = rd;
	(*str)[rd] = (unsigned char)(128);
	ft_bzero(&(*str)[i + 1], 128 - i);
	len *= 8;
	k = ft_num_byte(len);
	(rd < 56) ? (i = 56) : (i = 120);
	j = 0;
	while ((i != 64 || i != 128) && j < k)
		(*str)[i++] = (len >> (j++ * 8)) & 255;
}

void	ft_dellst(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_strdel((char**)(&(lst->content)));
		free(lst);
		lst = tmp;
	}
}

void ft_substr(unsigned char (*str)[129], unsigned char *s, int i, int len)
{
	int	j;

	j = 0;
	while (i < len)
		(*str)[j++] = s[i++];
	(*str)[j] = '\0';
}

void	ft_md5_s(unsigned char *s, unsigned int const init[], t_read *r)
{
	int		len;
	t_f		f;
	//t_list	*baf;
	int		i;
	int		rd;

	f.files = NULL;
	ft_bzero(r->str, 128);
	ft_init_list(&f, 5, "ABCD", init);
	len = ft_strlen((char*)s);
	i = 0;
	if (r->fl[3] != 1)
		printf("MD5 (\"%s\") = ", s);
	while (i < len)
	{
		ft_substr(&r->str, s, i, 64);
		rd = len - i;
		if (rd < 64)
		{
			ft_pad(rd, &r->str, len);
			ft_loop_call(&(f.files), r->str);
			if (rd >= 56)
				ft_loop_call(&(f.files), &r->str[64]);
			ft_m(&(f.files), &r->str, r->fl, NULL, NULL);
		}
		else
			ft_loop_call(&(f.files), r->str);
		i += 64;
	}
	if (r->fl[3] == 1 && r->fl[2] != 1)
		printf(" \"%s\"", s);
}

void	ft_md5_h(t_read *r, t_f *f, t_list *files)
{
	if (!((r->fl)[(r->e_k)[1]] == -2 && (r->e_k)[1] == 5) && ((r->e_k)[0] == 0 || ((r->e_k)[3] < 64 && (r->fl)[0] != 1)))
	{
		ft_pad((r->e_k)[3], &r->str, (r->e_k)[2]);
		ft_loop_call(&(f->files), r->str);
		if ((r->e_k)[3] >= 56)
			ft_loop_call(&(f->files), &r->str[64]);
		ft_m(&(f->files), &r->str, r->fl, files, f->err);
		(r->e_k)[2] = 0;
		if ((r->fl)[0] != 1 && files)
			files = files->next;
		if ((r->fl)[0] == 1)
			(r->fl)[0] = 0;
		printf("\n"); 
	}
	else if (!((r->fl)[(r->e_k)[1]] == -2 && (r->e_k)[1] == 5) && (r->e_k)[3] == 64) 
		ft_loop_call(&(f->files), r->str);
}

void	md5(t_read r, t_list *files, unsigned char *s)
{
	unsigned int const	init[4] = {0x67452301, 0xEFCDAB89, 0x98BADCFE,
	0x10325476};
	t_f					f;
	

	printf("ok5\n");
	(r.e_k)[1] = 5;
	printf("ok5\n");
	f.files = NULL;
	printf("ok5\n");
	f.err = NULL;
	ft_init_list(&f, 5, "ABCD", init);
	printf("ok\n");
	r.e_k[2] = 0;	
	r.e_k[0] = 1;
	while (r.fl[(r.e_k)[1]] == -2 || (r.e_k[1] != -1 && ((r.e_k)[3] = ft_read(&r)) >= 0))
	{
		printf("ok\n");
		r.e_k[2] += r.e_k[3];
		ft_md5_h(&r, &f, files);
		if (r.fl[r.e_k[1]] == -2)
		{
			r.fl[r.e_k[1]] = -3;
			ft_md5_s(s, init, &r);
			r.e_k[2] = 0;
			printf("\n"); 
			if (r.fl[r.e_k[1] + 1] == -1)
				break ;
		}
	}
	ft_dellst(f.files);
	ft_dellst(f.err);
}

void	ft_generate_words(unsigned int	(*w)[])
{
	int				i;
	unsigned int				s0;
	unsigned int				s1;

	i = 16;
	while (i < 64)
	{
		s0 = ft_rotr((*w)[i-15], 7) ^ ft_rotr((*w)[i-15], 18) ^ ((*w)[i-15] >> 3);
		s1 = ft_rotr((*w)[i-2], 17) ^ ft_rotr((*w)[i-2], 19) ^ ((*w)[i-2] >> 10);
		(*w)[i] = (*w)[i-16] + s0 + (*w)[i-7] + s1;
		++i;
	}
}

void	ft_reassign_h(unsigned int (*h)[], t_sha s)
{
	(*h)[7] = (*h)[6];
	(*h)[6] = (*h)[5];
	(*h)[5] = (*h)[4];
	(*h)[4] = (*h)[3] + s.t1;
	(*h)[3] = (*h)[2];
	(*h)[2] = (*h)[1];
	(*h)[1] = (*h)[0];
	(*h)[0] = s.t1 + s.t2;
}

void	ft_sha256_operations(t_sha *s, unsigned int h[], unsigned int w[], int i)
{
	s->s0 = ft_rotr(h[0], 2) ^ ft_rotr(h[0], 13) ^ ft_rotr(h[0],22);
	s->ma = (h[0] & h[1]) ^ (h[0] & h[2]) ^ (h[1] & h[2]);
	s->t2 = s->s0 + s->ma;
	s->s1 = ft_rotr(h[4], 6) ^ ft_rotr(h[4], 11) ^ ft_rotr(h[4], 25);
	s->ch = (h[4] & h[5]) ^ ((~h[4]) & h[6]);
	s->t1 = h[7] + s->s1 + s->ch + ft_k(i) + w[i];
}

void	ft_new_h(unsigned int (*h)[], unsigned int buf[])
{
	int		i;

	i = -1;
	while (++i < 8)
		(*h)[i] += buf[i];
}

void	ft_mainloop_sha256(unsigned int (*h)[], unsigned int w[])
{
	t_sha	s;
	int		i;
	unsigned int	buf[8];

	i = -1;
	while (++i < 8)
		buf[i] = (*h)[i];
	i = 0;
	while (i < 64)
	{
		ft_sha256_operations(&s, buf, w, i++);
		ft_reassign_h(&buf, s);
	}
	ft_new_h(h, buf);
}

void ft_pad_256(int rd, unsigned char (*str)[129], int len)
{
	int	i;
	int	j;
	int	k;

	i = rd;
	(*str)[rd] = (unsigned char)(128);
	ft_bzero(&(*str)[i + 1], 128 - i);
	len *= 8;
	k = ft_num_byte(len);
	(rd < 56) ? (i = 63) : (i = 127);
	j = 0;
	while ((i >= 56 || i >= 120) && j < k)
		(*str)[i--] = (len >> (j++ * 8)) & 255;
}

void	ft_stroll_256(unsigned char str[], unsigned int (*w)[], int amm)
{
	int				j;
	int				k;
	unsigned int	num;
	unsigned char	tmp;

	k = 0;
	num = 0;
	j = 15;
	while (--amm >= 0 && j >= 0)
	{
		tmp = str[amm];
		num = num | (tmp << k);
		k += 8;
		if (amm % 4 == 0)
		{
			(*w)[j] = num;
			num = 0;
			--j;
		}
	}
}

void	ft_loop_call256(unsigned char *str, unsigned int (*w)[], unsigned int (*h)[])
{
	ft_stroll_256(str, w, 64);
	ft_generate_words(w);
	ft_mainloop_sha256(h, *w);	
}

void ft_m256(unsigned int (*b)[], unsigned char (*s)[129], int fl[], t_list *f, t_list *e)
{
	int				k;
	int				l;
	unsigned int	h[8] = {0x6A09E667,0xBB67AE85,0x3C6EF372,0xA54FF53A,
								0x510E527F,0x9B05688C,0x1F83D9AB,0x5BE0CD19};

	if (f && fl[3] == -1 && fl[2] != 1 && fl[0] != 1)
		printf("SHA256 (");
	ft_out(&fl, f, 0, e);
	l = -1;
	while (++l < 8)
	{
		k = 24;
		while (k >= 0)
		{
			printf("%.2x", (unsigned int)(((*b)[l] >> k) & 255));
			k -= 8;
		}
	}
	ft_out(&fl, f, 1, e);
	k = -1;
	while (++k < 8 )
		(*b)[k] = h[k];
	ft_bzero(*s, 129);
}

void	ft_256_s(unsigned char *s, t_read *r)
{
	int				i[3];
	unsigned int	w[64];
	unsigned int	h[8] = {0x6A09E667,0xBB67AE85,0x3C6EF372,0xA54FF53A,
							0x510E527F,0x9B05688C,0x1F83D9AB,0x5BE0CD19};

	ft_bzero(r->str, 128);
	i[1] = ft_strlen((char*)s);
	i[0] = 0;
	if (r->fl[3] != 1)
		printf("SHA256 (\"%s\") = ", s);
	while (i[0] < i[1])
	{
		ft_substr(&(r->str), s, i[0], 64);
		i[2] = i[1] - i[0];
		if (i[2] < 64)
		{
			ft_pad_256(i[2], &(r->str), i[1]);
			ft_loop_call256((r->str), &w, &h);
			if (i[2] >= 56)
				ft_loop_call256(&(r->str[64]), &w, &h);
			ft_m256(&h, &(r->str), r->fl, NULL, NULL);
		}
		else
			ft_loop_call256(r->str, &w, &h);
		i[0] += 64;
	}
	if (r->fl[3] == 1 && r->fl[2] != 1)
		printf(" \"%s\"", s);
}

void	ft_sha_h(t_read *r, t_list *fl, t_list *e)
{
	unsigned int	h[8] = {0x6A09E667,0xBB67AE85,0x3C6EF372,0xA54FF53A,
							0x510E527F,0x9B05688C,0x1F83D9AB,0x5BE0CD19};
	unsigned int	w[64];

	if (!((r->fl)[(r->e_k)[1]] == -2 && (r->e_k)[1] == 5) && ((r->e_k)[0] == 0 || 
	((r->e_k)[2] < 64 && (r->fl)[0] != 1)))
		{
			ft_pad_256((r->e_k)[2], &(r->str), (r->e_k)[3]);
			ft_loop_call256(r->str, &w, &h);
			if ((r->e_k)[2] >= 56)
				ft_loop_call256(&(r->str[64]), &w, &h);
			ft_m256(&h, &(r->str), r->fl, fl, e);
			(r->e_k)[3] = 0;
			if ((r->fl)[0] != 1 && r->fl)
				fl = fl->next;
			if ((r->fl)[0] == 1)
				(r->fl)[0] = 0;
			printf("\n");
		}
		else if (!((r->fl)[(r->e_k)[1]] == -2 && (r->e_k)[1] == 5) && (r->e_k)[2] == 64)
			ft_loop_call256(r->str, &w, &h);
}

void	sha256(t_read r, t_list *files, unsigned char *s)
{
	t_list			*e;

	r.e_k[3] = 0;
	r.e_k[1] = 5;
	r.e_k[0] = 1;
	e = NULL;
	while (r.fl[r.e_k[1]] == -2 || (r.e_k[1] != -1 && (r.e_k[2] = ft_read(&r)) >= 0))
	{
		r.e_k[3] += r.e_k[2];
		ft_sha_h(&r, files, e);
		if (r.fl[r.e_k[1]] == -2)
		{
			r.fl[r.e_k[1]] = -3;
			ft_256_s(s, &r);
			r.e_k[3] = 0;
			printf("\n"); 
			if (r.fl[r.e_k[1] + 1] == -1)
				break ;
		}
	}
}

void	ft_fill_flags(int **fl, int num)
{
	int i;

	i = 0;
	while (i < num)
		(*fl)[i++] = -1;
}

void	ft_clean(t_list *files, t_list *err, unsigned char *s)
{
	t_list *tmp;

	tmp = err;
	while (tmp)
	{
		printf("%s\n", (char*)(tmp->content));
		tmp = tmp->next;
	}
	ft_strdel((char**)(&s));
	ft_dellst(files);
	ft_dellst(err);
}

void	ft_commands(int argc, char **argv, t_f flags)
{
	unsigned char		*s;
	const char			*tbl[2] = {"md5", "sha256"};
	static void			(*func[2])(t_read, t_list*,	unsigned char *) 
	= {md5, sha256};
	t_read				r;

	ft_bzero(r.str, 129);
	r.fl = (int*)malloc(sizeof(int) * (argc + 5));
	ft_fill_flags(&(r.fl), argc + 4);
	flags.files = NULL;
	flags.argc = argc;
	s = NULL;
	flags.err = NULL;
	ft_flags(argv, &r.fl, &flags, &s);
	argc = -1;
	while (++argc < 2)
	{
		if (argv[1] != NULL && ft_strcmp(argv[1], tbl[argc]) == 0)
		{
			printf("okok\n");
			func[argc](r, flags.files, s);
			ft_clean(flags.files, flags.err, s);
			return ;
		}
	}
	ft_error(argv[1]);
}

int		main(int argc, char **argv)
{
	t_f				flags;

	if (argc == 1)
	{
		write(1, "usage: ft_ssl command [command opts] [command args]\n", 52);
		return (0);
	}
	argv[argc] = NULL; 
	ft_commands(argc, argv, flags);
	return (0);
}
