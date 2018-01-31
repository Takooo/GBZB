#include<stdio.h>
int main(int argc, int argv[])
{
	unsigned char s[10] = "¹ú";
	unsigned char h[10] = "±ê";
	unsigned char x[10] = "ÕÜ";
	unsigned char y[10] = "±ê";
	unsigned char u1[32];
	unsigned char u2[32];
	unsigned char u3[32];
	unsigned char u4[32];
	int q, w, j, k, i;
	int flag;
	long ofs;
	FILE *fp;
	unsigned char key[8] = {
		0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
	};
	q = (s[0] - 0xA1);
	w = (s[1] - 0xA1);

	ofs = (q * 94 + w) * 32L;
	fp = fopen("Hzk16.×Ö¿â", "rb");
	fseek(fp, ofs, SEEK_SET);
	fread(u1, 1, 32, fp);
	q = (h[0] - 0xA1);
	w = (h[1] - 0xA1);
	ofs = (q * 94 + w) * 32L;
	fseek(fp, ofs, SEEK_SET);
	fread(u2, 1, 32, fp);
	fclose(fp);


	fp = fopen("mhzk16.×Ö¿â", "rb");
	q = (x[0] - 0xA1);
	w = (x[1] - 0xA1);
	ofs = ((q * 94 + w) + 256) * 32L;
	fseek(fp, ofs, SEEK_SET);
	fread(u3, 1, 32, fp);
	q = (y[0] - 0xA1);
	w = (y[1] - 0xA1);
	ofs = ((q * 94 + w) + 256) * 32L;
	fseek(fp, ofs, SEEK_SET);
	fread(u4, 1, 32, fp);
	fclose(fp);

	for (k = 0; k < 16; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 8; i++) {
				flag = u1[k * 2 + j] & key[i];
				printf("%s", flag ? "¡ñ" : "¡ð");
			}
		}
		printf("\n");
	}
	printf("\n");
	for (k = 0; k < 16; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 8; i++) {
				flag = u2[k * 2 + j] & key[i];
				printf("%s", flag ? "¡ñ" : "¡ð");
			}
		}
		printf("\n");
	}
	printf("\n");
	for (k = 0; k < 16; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 8; i++) {
				flag = u3[k * 2 + j] & key[i];
				printf("%s", flag ? "¡ñ" : "¡ð");
			}
		}
		printf("\n");
	}
	printf("\n");
	for (k = 0; k < 16; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 8; i++) {
				flag = u4[k * 2 + j] & key[i];
				printf("%s", flag ? "¡ñ" : "¡ð");
			}
		}
		printf("\n");
	}
	return 0;
}