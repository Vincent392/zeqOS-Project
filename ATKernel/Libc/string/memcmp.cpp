#include <string.hpp>
int memcmp(const void* s1, const void* s2, size_t len)
{
	const unsigned char *u1 = (const unsigned char*)s1;
	const unsigned char *u2 = (const unsigned char*)s2;

	while (len-- > 0)
	{
		if (*u1++ != *u2++)
			return u1[-1] < u2[-1] ? -1 : 1;
	}
	return 0;
}