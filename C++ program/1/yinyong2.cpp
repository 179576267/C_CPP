#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

struct Apple{
	int size;
	char *type;
};

void getApple(Apple **a){
	Apple *p = (Apple*) malloc (sizeof(Apple));
	p->size = 20;
	p->type = "qwe";
	*a = p;
}

//指针的引用替代二级指针
void getApple(Apple* &a){
	a = (Apple*) malloc (sizeof(Apple));
	a->size = 40;
	a->type = "asd";
}

//常引用作为参赛，其引用对象不能改变
void myprintf(const int &a){
	int b = 2;
	//a = b; 不允许
	printf("a value can not be change\n");
}

//引用 ：只要作为函数的参数的返回值
int main(){
	Apple *a = NULL;
	getApple(&a);
	cout << a->type <<","<< a->size << endl;
	free(a);

	int c = 1;
	myprintf(c);	
	
	
}
