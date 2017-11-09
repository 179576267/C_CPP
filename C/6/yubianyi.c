#include <stdio.h>
#include<stdlib.h>

#pragma once //

#define _JNI_H

#define MAX_LENGTH 20

#define HAHA(a,b) a + b

#define PRINT() printf("wangzhenfei\n");



#ifndef HOHO(a,b) a - b
#define HOHO(a,b) a - b
#endif



void to_read(char * str){printf("read : %s\n", str);}
void to_write(char * str){printf("write : %s\n", str);}
//宏函数
#define jni(NAME, arg) to_##NAME(arg)

//可变参数宏函数 
#define LOG(FORMAT,...) printf(FORMAT, __VA_ARGS__)
#define LOG_I(FORMAT,...) printf("INFO: "); printf(FORMAT, __VA_ARGS__)

//预便宜替换文件 相当以直接写成my.txt里面的内容
void main(){
	#include "my.txt"
	printf("%d\n", HOHO(1,2) * HOHO(3,4));
	printf("%d\n", HAHA(1,2) * HAHA(3,4));
	//相当于	
	printf("%d\n", 1 + 2 * 3 + 4);
	PRINT();
	jni(read, "haha");
	jni(write, "hehe");
	LOG("%s %d\n", "大小：", 100);
	LOG_I("%s %d\n", "大小：", 1000);
}
