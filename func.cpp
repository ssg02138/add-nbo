#include "func.h"

void  write_0x12345678(uint8_t *b1, uint8_t *b2) {
	uint32_t *p1 = reinterpret_cast<uint32_t*>(b1);
	uint32_t *p2 = reinterpret_cast<uint32_t*>(b2);

	uint32_t r1 = ntohl(*p1);
	uint32_t r2 = ntohl(*p2);

	uint32_t r3 = r1 + r2;

	printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", r1, r1, r2, r2, r3, r3);
}

void run(char *n1, char *n2) {
	FILE *f1, *f2;
	uint8_t b1[4];
	uint8_t b2[4];

	f1 = fopen(n1, "rb");
	f2 = fopen(n2, "rb");

	fread(b1,8,1,f1);
	fread(b2,8,1,f2);

	fclose(f1);
	fclose(f2);

	write_0x12345678(b1, b2);
}