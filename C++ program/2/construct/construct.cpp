#include<stdio.h>
#include<iostream>
#include<stdarg.h> // 可变参数
#include<stdlib.h>
#include<string.h>
using namespace std;

class User{
	private:
		int age;
		char *name;
	
	public:
		//构造函数只会调用一个
		User(){
			this->name = (char*)malloc(100);
			strcpy(this->name, "no");
			this->age = 25; 	
			cout << "no arg construct has call" << endl;
		}
		User(int age, char *name){
			this->age = age;
			this->name = name;
			cout << this->age << endl;
			cout << this->name << endl;		
		}

		//析构函数无参数，释放本类,作回收处理
		~User(){
			delete(this->name);
			cout << "析构函数调用了"<<endl; 		
		}
		
		//拷贝构造函数 深拷贝
		//默认拷贝构造函数就算值拷贝  （浅拷贝问题）
		//拷贝构造函数场景：函数传参，声明时候赋值（User u6 = u1;),
		//作为函数的返回值 return 并给变量赋值（User u6 = func();）
		
		User(const User &obj){
			this->name = (char*) malloc(strlen(obj.name) + 1);
			strcpy(this->name, obj.name);
			this->age = obj.age;	
			cout << "拷贝构造函数"<<endl; 			
		}
		
		void myprintf(){
			cout << name << " : " << age << endl;
		}
};

int main(){
	
	/*
	char *name = (char*)malloc(100);
	strcpy(name, "wzf");
	User u2(20,name);

	name = (char*)malloc(100);
	strcpy(name, "hahaha");
	User u3 = User(28, name);

	name = (char*)malloc(100);
	strcpy(name, "hehehhe");
	User *u4 = new User(30, name);
	*/

	User u1;
	//浅拷贝构造函数问题 值拷贝->>u1的name指向一块内存区域，u6拷贝u1的参数，u6的name也指向同一块内存区域
	//u1 delete的时候name被释放，
	//当u6 delete的时候，同一块内存区域的name又被释放一次
	//需要深拷贝来解决
	User u6 = u1;
	
	u6.myprintf();
}
