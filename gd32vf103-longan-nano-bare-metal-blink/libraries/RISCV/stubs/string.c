#include <stdint.h>
#include <stddef.h>
#include <string.h>

__attribute__((weak)) size_t strlen(const char *s)
{
	const char *p = s;
	char c;

	do {
		c = *p++;
	} while (c != '\0');

	return (uintptr_t)p - (uintptr_t)s - 1;
}

__attribute__((weak)) void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	if (n > 0) {
		char *cdest = dest;
		const char *csrc = src;
		const char *cend = csrc + n;

		do {
			*cdest++ = *csrc++;
		} while (csrc < cend);
	}

	return dest;
}
