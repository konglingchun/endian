//大小端测试程序
#include <stdio.h>
#include <stdlib.h>

/*
大小端:
小端：低地址存低位
大端：低地址存高位
*/
enum endian_t {
	ENDIAN_LITTLE,
	ENDIAN_BIG,
};

int check_cpu_endian(void)
{
    typedef union {
        unsigned int i;
        unsigned char s[4];
    }endian_test_t;
	
	endian_test_t c;
	int endian;
	
    c.i = 0x04030201;
    printf("%s\n", (0x01 == c.s[0]) ? "little endian" : "big endian");
	endian = (0x01 == c.s[0]) ? ENDIAN_LITTLE : ENDIAN_BIG;
	return endian;
}

int main(int argc, char *argv[])
{
    check_cpu_endian();
    return 0;
}
