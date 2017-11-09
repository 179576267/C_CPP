#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//指针交换变量值
void swap_1(int *a, int *b){
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//引用交换变量值
void swap_2(int &a, int &b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//引用 ：只要作为函数的参数的返回值
//引用必须赋初始值,且不能为空
//int &b;
//引用在传参的时候不会在函数栈产生变量副本，而是直接操作变量
//指针是间接操作变量，可读性强
int main(){
	//变量名就算一个门牌号
	int a = 10;
	//b就是这个内存空间另外一个引用, &符号在类型前面表示引用
	int &b = a;
	b = 120;
	cout<< a << " " << &a << endl;
	cout<< b << " " << &b <<endl;

	//交换两个变量的值
	int x = 10; 
	int y = 20;
	cout<< "befer: " << "x = " << x << ",y = "<< y <<endl;
	//swap_1(&x, &y);
	//a为x别名，b为y的别名
	swap_2(x, y);
	cout<< "after: " << "x = " << x << ",y = "<< y <<endl;
}
