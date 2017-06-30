#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
	//使用字符数组
	//char str[] = {'C','H','I','N','A','\0'};
	char str[6] = {'C','H','I','N','A'};
	//char str[] = "china";	
	str[0] = 'o';
	printf("%s\n",str);

	//通过字符指针
	char *str2 = "hello world!";
	//不能改，字符指针指向的字符串是存放常量区，但是可以访问
	//str2[0] = 'w';
	printf("%s\n",str2);
	while(*str2){
		printf("%c\n", *str2);
		str2++;	
	}


	/**
	字符串相关函数
	http://www.kuqin.com/clib/
	1.	strcpy(des,src)
	2.strcat(des.src)
	**/

	char dest[50];
 	char *a = "wangzhenfei";
	char *b = "wandonful";
	strcpy(dest, a);
	strcat(dest, b);
	printf("%s\n", strcmp(a,b)? "a > b" : "a < b");//忽略大小写
	printf("%s\n", dest);
	//查找第一个匹配位置地址
	char *p = strchr(a, 'f');
	printf("first show index is : %d\n", p - a);

	
}

