int		ft_cntdigits(long long n)
{
		int count = 0;

		while(n != 0)
		{
				n /= 10;
				++count;
		}
		return (count);
}
