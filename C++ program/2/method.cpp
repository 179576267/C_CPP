#include<stdio.h>
#include<iostream>
#include<stdarg.h> // 可变参数
using namespace std;

//函数默认值,中间某个参赛有默认值的情况，其后所有参赛都得有
void myprintf(int a = 10){
	cout << a << endl;
}

//可变参数
void myprintf2(int a,int b,...){
	//通过include<stdarg.h> 引入可变参赛指针	
	va_list args_p;
	//读取可变参数部分，b是最后一个固定参赛
	va_start(args_p,b);
	cout << va_arg(args_p,int) << endl;
	cout << va_arg(args_p,int) << endl;
	//结束	
	va_end(args_p);
}

//循环读取
void myprintf3(int count,...){
	//通过include<stdarg.h> 引入可变参赛指针	
	va_list args_p;
	//读取可变参数部分，b是最后一个固定参赛
	va_start(args_p,count);
	int i = 0;
	for(;i < count; i++){
		cout << va_arg(args_p,int) << endl;
	}
	//结束	
	va_end(args_p);
}

int main(){
	myprintf();
	myprintf2(2,5,'c',345,6,'h',54,35);
	myprintf3(7,5,'c',345,6,'h',54,35);
}
