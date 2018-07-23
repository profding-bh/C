// 单精度(32位)浮点数的解码程序，忽略处理inf，NaN，0等形式的浮点数。

/* 
 * floatdis32.c
 * dissection for IEEE754 floating-point number (32 bit)
 * structure: Sign    : 1bit
 *            Exponent: 8bit
 *            Mantissa: 23bit
 * algorithm: (-1)^S*(1.M)*2^(E-127)
 * 
 * Time-stamp: <2012-07-30 09:58:15 root>
 * snallie@tom.com
 * 
 * make: gcc f.c -o f -lm
 *
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LEN 32
#define BIAS_EXPONENT 127

void ascStrAdd(char *a, char *b, char *sum);
void asciiNumAdd_aDecimal(char a, char b, char *sum, char *Hcarry,
              char Lcarry);
char fltable[][33] = {
    "00000000000000000000000000000000",    /* Zero */
    "50000000000000000000000000000000",    /* 2^-1 */
    "25000000000000000000000000000000",    /* 2^-2 */
    "12500000000000000000000000000000",    /* 2^-3 */
    "06250000000000000000000000000000",    /* 2^-4 */
    "03125000000000000000000000000000",    /* 2^-5 */
    "01562500000000000000000000000000",    /* 2^-6 */
    "00781250000000000000000000000000",    /* 2^-7 */
    "00390625000000000000000000000000",    /* 2^-8 */
    "00195312500000000000000000000000",    /* 2^-9 */
    "00097656250000000000000000000000",    /* 2^-10 */
    "00048828125000000000000000000000",    /* 2^-11 */
    "00024414062500000000000000000000",    /* 2^-12 */
    "00012207031250000000000000000000",    /* 2^-13 */
    "00006103515625000000000000000000",    /* 2^-14 */
    "00003051757812500000000000000000",    /* 2^-15 */
    "00001525878906250000000000000000",    /* 2^-16 */
    "00000762939453125000000000000000",    /* 2^-17 */
    "00000381469726562500000000000000",    /* 2^-18 */
    "00000190734863281250000000000000",    /* 2^-19 */
    "00000095367431640625000000000000",    /* 2^-20 */
    "00000047683715820312500000000000",    /* 2^-21 */
    "00000023841857910156250000000000",    /* 2^-22 */
    "00000011920928955078125000000000",    /* 2^-23 */
    "00000005960464477539062500000000",    /* 2^-24 */
    "00000002980232238769531250000000",    /* 2^-25 */
    "00000001490116119384765625000000",    /* 2^-26 */
    "00000000745058059692382812500000",    /* 2^-27 */
    "00000000372529029846191406250000",    /* 2^-28 */
    "00000000186264514923095703125000",    /* 2^-29 */
    "00000000093132257461547851562500",    /* 2^-30 */
    "00000000046566128730773925781250",    /* 2^-31 */
    "00000000023283064365386962890625",    /* 2^-32 */
};

int main(int argc, char **argv)
{
    /*
       char:1    short:2    int:4    long:4    float:4    double:8
     */
    char buf[33];
    buf[32] = 0;
    float f = 100.8912345600108992;    //3.40E38;           //100.89001089925383;
    char *p = (char *) (&f);
    unsigned int *pi = (int *) (&f);
    unsigned int k;
    int i = 0;

    if (argc > 1) {
    f = atof(argv[1]);
    }
    printf
    ("<<<< IEEE 754 single precision float-point numeral (32bit) dissection >>>>\n");
    k = *pi;
    printf("float number to be dissected: f = %-32.32g\n", f);

    for (i = 3, printf("Hex    dump: "); i >= 0; i--)
    printf("%02X ", p[i] & 0xff);
    printf("\n");

    for (i = 31, printf("Binary dump: "); i >= 0; i--) {
    buf[i] = (char) (k % 2 + 0x30);
    k >>= 1;
    }

    for (i = 0; i < 32; i++) {
    printf("%c%s", buf[i], (i + 1) % 4 == 0 ? " " : "");
    }

    for (i = 0; i < 32; i++) {
    if (i == 0)
        printf("\nsign    : %c \nexponent: ", buf[i]);
    if (i > 0 && i <= 8)
        printf("%c", buf[i]);
    if (i == 8)
        printf("\nmantissa: ");
    if (i > 8)
        printf("%c", buf[i]);
    }
    printf("\n");

    {                // dissection
    int i;
    float tmpflt;
    char mantissa[33] = "00000000000000000000000000000000";
    char tmpMant[36];

    int exponent = 0;
    mantissa[32] = '\0';
    char *buf2 = buf + 9;
    for (i = 0; i < 23; i++)    // compute mantissa to decimal
    {
        if (buf2[i] != '0') {
        ascStrAdd(mantissa, fltable[i + 1], mantissa);
        printf("%s\n", mantissa);
        }
    }

    mantissa[32] = '\0';
    for (i = 1; i < 9; i++)    // compute exponent to integer
    {
        if (buf[i] != '0') {
        exponent += pow(2, 8 - i);
        }
    }
    exponent -= BIAS_EXPONENT;
    printf("Integer exponent:##%d\n", exponent);
    printf("result:\t\t    %c1.%sE2^%d\n", buf[0]==0x31?'-':' ',mantissa, exponent);

    // transform the binary format to float , stored in tmpflt
    tmpMant[1] = '.';
    tmpMant[0] = '0';
    strcpy(tmpMant + 2, mantissa);
    tmpflt = atof(tmpMant) + 1;
    printf("Decimal equivalent: %c%-64.64g\n",buf[0]==0x31?'-':' ',
           tmpflt * pow(2, exponent));
    }
    return 0;
}

void ascStrAdd(char *a, char *b, char *sum)
{
    int i;
    char Lcarry = 0x30;
    //    char Hcarry = 0x30;

    for (i = 31; i >= 0; i--) {
    asciiNumAdd_aDecimal(a[i], b[i], &sum[i], &Lcarry, Lcarry);
    }
}

void asciiNumAdd_aDecimal(char a, char b, char *sum, char *Hcarry,
              char Lcarry)
{
    int ta = a - 0x30;
    int tb = b - 0x30;
    int tLc = Lcarry - '0';
    *sum = (ta + tb + tLc) % 10 + 0x30;

    if (ta + tb > 9 || ta + tLc > 9 || tb + tLc > 9 || ta + tb + tLc > 9) {
    *Hcarry = 0x31;        //1
    } else {
    *Hcarry = 0x30;        //0
    }
}

