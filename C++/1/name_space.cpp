#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//标准命名空间, 类似导包，解决重名
using namespace std; 

//自定义命名空间,两个全局变量
namespace NSP_A{ int a = 9;}
namespace NSP_B{ 
	int a = 12;
	typedef struct Teacher{
			int age;
			char name[20];		
		}Teacher;	
}
//命名空间嵌套，不多用
namespace NSP_C{ 
	int a = 12;
	namespace NSP_D{ 
		int c = 182;
		typedef struct Teacher{
			int age;
			char name[20];		
		}Teacher;	
	}
}


int main(){
	printf("this is c + +\n");
	//运算符重载
	cout << "this is c++ print by c++" <<endl;
	//使用自定义命名空间
	//::访问修饰符相当于java中的.
	cout<< NSP_A:: a<< endl;
	cout<< NSP_B:: a<< endl;
	cout<< NSP_C:: NSP_D::c<< endl;
	//访问结构体
	struct NSP_C:: NSP_D :: Teacher t1;
	//简化
	using namespace NSP_C::NSP_D;
	Teacher t2;
}
