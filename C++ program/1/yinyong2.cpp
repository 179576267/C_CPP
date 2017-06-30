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


//引用 ：只要作为函数的参数的返回值
int main(){
	Apple *a = NULL;
	getApple(&a);
	cout << a->type <<","<< a->size << endl;
	free(a);
}
