#include "encipher.h"
encipher::encipher()
{
}
string encipher::ascii_to_sha1(string scr)
{
	resetmagcinum();
	__int64 a = H0;
	__int64 b = H1;
	__int64 c = H2;
	__int64 d = H3;
	__int64 e = H4;
	string ans;
	array<array<bool, 32>, 16>M{};
	array<array<bool, 32>, 80>w{};
	array<__int64, 80>W{};
	array<array<bool, 8>, 64>bin{};
	__int64 i = 0, n = 0, m = 0;//循环用变量
	__int64 temp = 0;
	int length = 0;
	length = (int)scr.length();//Ascii转二进制
	for (char x : scr)
	{
		for (i = 0; i <= 7; i++)
		{
			bin[n][7 - i] = x % 2;
			x = (x - (x % 2)) / 2;
		}
		n++;
	}
	if (0 < n || n > 63)
	{
		return "-1";
	}
	bin[n][0] = true;
	length *= 8;
	for (i = 0; i <= 7; i++)//编写长度信息
	{
		bin[63][7 - i] = length % 2;
		length = (length - (length % 2)) / 2;
	}
	for (n = 0; n < 16; n++)//转M[t]
	{
		for (i = 0; i < 8; i++)
		{
			/*for (m = 0; m < 31; m++)
				{
					w[n][m] = w[n][m + 1];
				}
				w[n][31] = 0;*/
			M[n][i] = bin[4 * n][i];
			M[n][i + 8] = bin[4 * n + 1][i];
			M[n][i + 16] = bin[4 * n + 2][i];
			M[n][i + 24] = bin[4 * n + 3][i];
		}
	}
	for (n = 0; n < 80; n++)//转w[t]
	{
		if (n < 16)//前16段照抄
		{
			for (i = 0; i < 32; i++)
			{
				w[n][i] = M[n][i];
			}
		}
		else//后面的段值为n-3 n-8 n-14 n-16 项异或运算后左移一位的值
		{
			for (i = 0; i < 32; i++)//异或
			{
				w[n][i] = w[n - 3][i] ^ w[n - 8][i] ^ w[n - 14][i] ^ w[n - 16][i];
			}
			temp = w[n][0];
			for (i = 0; i < 31; i++)//左移
			{
				w[n][i] = w[n][i + 1];
			}
			w[n][31] = temp;
		}
	}
	for (n = 0; n < 80; n++)//w[t]转W[t]
	{
		for (i = 0; i < 32; i++)
		{
			W[n] += (long long)(w[n][i] * pow(2, 31 - i));
		}
	}
	for (i = 0; i < 80; i++)
	{
		temp = Plus(Plus(Plus(Plus((_rotl((unsigned int)H0, 5)), ft((unsigned int)H1, (unsigned int)H2, (unsigned int)H3, i)), (unsigned int)H4), (unsigned int)Kt(i)), (unsigned int)W[i]);
		H4 = H3;
		H3 = H2;
		H2 = _rotl((unsigned int)H1, 30);
		H1 = H0;
		H0 = temp;
	}
	H0 = Plus(H0, a);
	H1 = Plus(H1, b);
	H2 = Plus(H2, c);
	H3 = Plus(H3, d);
	H4 = Plus(H4, e);
	
	printf("%I64d", H0);
	printf("%I64d", H1);
	printf("%I64d", H2);
	printf("%I64d", H3);
	printf("%I64d\n", H4);
	return ;
}

__int64 encipher::Plus(__int64 x, __int64 y)
{
	__int64 plus = (__int64)pow(2, 32);
	return (x + y) % plus;
}

__int64 encipher::ft(__int64 x, __int64 y, __int64 z, __int64 i)
{
	if (0 <= i && i <= 19)
	{
		return (x & y) ^ ((~x) & z);
	}
	else if (20 <= i && i <= 39)
	{
		return x ^ y ^ z;
	}
	else if (40 <= i && i <= 59)
	{
		return (x & y) ^ (x & z) ^ (y & z);
	}
	else if (60 <= i && i <= 79)
	{
		return x ^ y ^ z;
	}
	else return -1;
}

__int64 encipher::Kt(__int64 i)
{
	if (0 <= i && i <= 19)
		return 0x5a827999;
	else if (20 <= i && i <= 39)
		return 0x6ed9eba1;
	else if (40 <= i && i <= 59)
		return 0x8f1bbcdc;
	else if (60 <= i && i <= 79)
		return 0xca62c1d6;
	else return -1;
}

void encipher::resetmagcinum()
{
	H0 = 0x67452301;
	H1 = 0xefcdab89;
	H2 = 0x98badcfe;
	H3 = 0x10325476;
	H4 = 0xc3d2e1f0;
}
