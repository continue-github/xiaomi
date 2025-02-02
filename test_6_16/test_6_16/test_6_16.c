#include<stdio.h>

// Release版本 编译 是对代码进行了优化
// Debug  程序员视角


// 整数的的二进制表示有三种方法------>内存中存放的是补码的二进制
// 1. 正整数的原码、反码、补码相同
// 2. 负整数的原码、反码、补码需要通过计算得到
// 原码：直接通过正负的形式写出的二进制序列就是原码
// 反码：原码的符号位不变，其他位按位取反
// 补码：反码加1得到补码
// 



short int test()
{
	short int m = 2;
	if (*(char*)&m == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}


int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	/*
	*
	*  -1是整形 32个bit位 保存在char类型时候低位截断
	*  %d是打印整形   有符号时候高位补1  无符号高位补0  
	*  补位结束补码转换原码打印
	*/
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);

//******************大小端判断**********************
	short ma = test();
	if (ma == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	printf("%d\n", ma);

	/*************     习题一    *************/
	char d = -128;
	//10000000000000000000000010000000
	//11111111111111111111111101111111
	//11111111111111111111111110000000 -->补码

	printf("%u\n", d);  //被当作无符号数打印 char类型有符号补“1”11111111111111111111111110000000
	/*************     习题二    *************/

	char e = 128; // char -128~127;
	//00000000000000000000000010000000

	printf("%u\n", e);  //被当作无符号数打印 char类型有符号补“1”11111111111111111111111110000000

	/*************     习题三    *************/
	int i = -20;
	unsigned int j = 10;
	// 10000000000000000000000000010100    -20
	// 11111111111111111111111111101011
	//  
	// 11111111111111111111111111101100   -20 补码
	// 00000000000000000000000000001010    10 补码
	// 11111111111111111111111111110110    结果 补码 最高位为1被认为是有符号数
	// 10000000000000000000000000001001
	// 10000000000000000000000000001010    -10 
	
	printf("%d\n", i+j);  // 测试
	return 0;
}


