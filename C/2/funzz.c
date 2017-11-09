#include<stdio.h>
//函数指针
//函数名称就是函数地址
/*
void function(char* str){
	printf("this is function define:%s\n", str);
}

void main(){
	printf("%#x\n", function);
	printf("%#x\n", &function);
	void(* _fun)(char* str)=function;
	_fun("佛教哦iewhjfoiwef");

}
*/

int add(int a, int b){ return a + b;}

int minus(int a, int b){ return a - b;}

//msg函数需要传递一个函数指针参赛,函数指针的参数只用写类型声明
typedef int(*FUN_P)(int, int);
void funmessage(char* message, FUN_P p, int a, int b){
	int result = p(a,b);
	printf("%s:%d\n", message, result);
}

void funmessage2(char* message, int(*fun_p)(int, int), int a, int b){
	int result = fun_p(a,b);
	printf("%s:%d\n", message, result);
}

void main(){
	funmessage("计算结果", add, 10, 5);
	funmessage2("计算结果", minus, 10, 5);
}
