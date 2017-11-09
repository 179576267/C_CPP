#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
//标准命名空间, 类似导包，解决重名
using namespace std; 
//类和结构体区别： 类能继承，结构图不行
//圆
//const double PI = 3.141592654;
#define PI 3.141592654
class MyCircle{
	//属性
	private:
		double r;
		double s;
		void a(){}		
	public:
		double leng;	
		void setR(double r){this->r = r;}
		double getS(){return PI * r * r;}
};

//结构体发生改变，相对于c
struct Teacher{
	private:
		char name[20];
		int age;
	public:
		void setInfo(int age, char* name){
			this->age = age;
			strcpy(this->name, name);		
		}
		void say(){
				cout << "my name is :" << this->name<< ",age is :"<<this->age << "岁" << endl;
		}
};

int main(){
	//多了一个bool类型
	bool isA = true;//大于O都是True
	if(isA){
		cout << "hello isA" << endl;
		cout << "sizeof bool:" << sizeof(bool)<< endl;
	}
	
	MyCircle c1;
	c1.setR(52);
	cout << "圆的面积是：" << c1.getS() << endl;
	MyCircle *pc = new MyCircle();
	pc->setR(52);
	cout << "圆的面积是：" << pc->getS() << endl;

	//结构体不需要写struct
	Teacher t;
	t.setInfo(25, "wzf");
	t.say();

	int a = 10, b = 20;
	//将最大值赋值为30， c不可以
	(a > b ? a : b) = 30;
	cout << b << endl;
}
