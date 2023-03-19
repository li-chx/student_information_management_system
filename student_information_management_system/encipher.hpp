#pragma once
#include "global.hpp"
using namespace std;
class encipher
{
public:
	encipher();
	string ascii_to_sha1(string scr);
private:
	__int64 Plus(__int64 x, __int64 y);
	__int64 ft(__int64 x, __int64 y, __int64 z, __int64 i);
	__int64 Kt(__int64 i);
	void resetmagcinum();
	__int64 H0 = 0x67452301;
	__int64 H1 = 0xefcdab89;
	__int64 H2 = 0x98badcfe;
	__int64 H3 = 0x10325476;
	__int64 H4 = 0xc3d2e1f0;
};
extern encipher enci;