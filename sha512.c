
void ft_pad_512(int rd, unsigned char **str, int len)
{
	int	i;
	int	j;
	int	k;

	i = rd;
	(*str)[rd] = (unsigned char)(128);
	ft_bzero(&(*str)[i + 1], 256 - i);
	len *= 8;
	k = ft_num_byte(len);
	(rd < 56) ? (i = 127) : (i = 255);
	j = 0;
	while ((i >= 112 || i >= 240) && j < k)
		(*str)[i--] = (len >> (j++ * 8)) & 255;
}

unsigned long long ft_ch(unsigned long long x, unsigned long long y, unsigned long long z)
{
	return ((x & y) ^ ( (~x) & z));
}

unsigned long long ft_maj(unsigned long long x, unsigned long long y, unsigned long long z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

unsigned long long ft_bsig0(unsigned long long x)
{
	return (ft_rotr(x, 28) ^ ft_rotr(x, 34) ^ ft_rotr(x, 39));
}

unsigned long long ft_bsig1(unsigned long long x)
{
	return (ft_rotr(x, 14) ^ ft_rotr(x, 18) ^ ft_rotr(x, 41));
}

unsigned long long ft_ssig0(unsigned long long x)
{
	return (ft_rotr(x, 1) ^ ft_rotr(x, 8) ^ (x >> 7));
}

unsigned long long ft_ssig1(unsigned long long x)
{
	return (ft_rotr(x, 19) ^ ft_rotr(x, 61) ^ (x >> 6));
}

unsigned long long ft_k_512(int i)
{
	unsigned long long const k[80] = {0x428a2f98d728ae22, 0x7137449123ef65cd,
	0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c,
	0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
	0x9bdc06a725c71235, 0xc19bf174cf692694, 0xe49b69c19ef14ad2,
	0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4,
	0x76f988da831153b5, 0x983e5152ee66dfab, 0xa831c66d2db43210,
	0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2,
	0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70, 
	0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b, 0xa2bfe8a14cf10364,
	0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a,
	0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63,
	0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72,
	0x8cc702081a6439ec, 0x90befffa23631e28, 0xa4506cebde82bde9,
	0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae,
	0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493,
	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c, 0x4cc5d4becb3e42b6,
	0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

	return (k[i]);
}

void	ft_stroll_512(unsigned char *str, unsigned long long (*w)[], int amm)
{
	int					j;
	int					k;
	unsigned long long	num;
	unsigned char		tmp;

	k = 0;
	num = 0;
	j = 15;
	while (--amm >= 0 && j >= 0)
	{
		tmp = str[amm];
		num = num | (tmp << k);
		k += 4;
		if (amm % 4 == 0)
		{
			(*w)[j--] = num;
			num = 0;
			k = 0;
		}
	}
}

void	ft_generate_words_512(unsigned long long	(*w)[])
{
	int				i;

	i = 16;
	while (i < 80)
	{
		(*w)[i] = ft_ssig1((*w)[i - 2]) + (*w)[i - 7] + ft_ssig0(i - 15) + (*w)[i - 16];
		++i;
	}
}

void	ft_new_h_512(unsigned long long (*h)[], unsigned long long buf[])
{
	int		i;

	i = -1;
	while (++i < 8)
		(*h)[i] += buf[i];
}

void ft_m512(unsigned long long (*baf)[], unsigned char **str, int fl[], t_list *files, t_list *ech)
{
	int					k;
	int					l;
	unsigned long long	h[8] = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
	0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1, 0x510e527fade682d1,
	0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};

	ft_out(&fl, files, 0, ech);
	l = 0;
	while (l < 8)
	{
		k = 56;
		while (k >= 0)
		{
			printf("%.2llx", (unsigned long long)(((*baf)[l] >> k) & 255));
			k -= 8;
		}
		++l;
	}
	ft_out(&fl, files, 1, ech);
	k = -1;
	while (++k < 8 )
		(*baf)[k] = h[k];
	ft_bzero(*str, 129);
}

void	ft_mainloop_sha512(unsigned long long (*h)[], unsigned long long w[])
{
	int		i;
	unsigned long long t1;
	unsigned long long t2;
	unsigned long long	buf[8];

	i = -1;
	while (++i < 8)
		buf[i] = (*h)[i];
	i = 0;
	while (i < 80)
	{
		t1 = buf[7] + ft_bsig1(buf[4]) + ft_ch(buf[4], buf[5], buf[6]) + ft_k_512(i) + w[i];
		t2 = ft_bsig0(buf[0]) + ft_maj(buf[0], buf[1], buf[2]);
		buf[7] = buf[6];
		buf[6] = buf[5];
		buf[5] = buf[4];
		buf[4] = buf[3] + t1;
		buf[3] = buf[2];
		buf[2] = buf[1];
		buf[1] = buf[0];
		buf[0] = t1 + t2;
		++i;
	}

	ft_new_h_512(h, buf);
}

void	ft_loop_call512(unsigned char *str, unsigned long long (*w)[], unsigned long long (*h)[])
{
	ft_stroll_512(str, w, 128);
	ft_generate_words_512(w);
	ft_mainloop_sha512(h, *w);	
}

void sha512(int fl[], unsigned char str[], t_list *files, unsigned char *s)
{
	int rd;
	int e_k[2];
	int len;
	t_list	*ech;
	unsigned long long	w[80];
	unsigned long long	h[8] = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
	0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1, 0x510e527fade682d1,
	0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};

	e_k[0] = 1;
	e_k[1] = 4;
	ech = NULL;
	len = 0;
	if (s)
		printf("%s\n", s);
	while (e_k[1] != -1 && (rd = ft_read(fl, &str, 128, &e_k, &ech)) >= 0)
	{
		len += rd;
		if (e_k[0] == 0 || (rd < 128 && fl[0] != 1))
		{
			ft_pad_512(rd, &str, len);
			ft_loop_call512(str, &w, &h);
			if (rd >= 56)
				ft_loop_call512(&str[64], &w, &h);
			ft_m512(&h, &str, fl, files, ech);
			len = 0;
			if (files)
				files = files->next;
		}
		else if (rd == 64)
			ft_loop_call512(str, &w, &h);
	}
	if (files)
		printf("(%s) ", (char*)(files->content));
	printf("\n");
}
