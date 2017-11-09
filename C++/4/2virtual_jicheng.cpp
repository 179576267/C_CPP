#include"../header.h"


//继承，子类对象调用父类成员
class A{
	public:
		int sex;
};

//virtual 虚继承，解决二义性方法2， 不同路径继承而来的同名成员只有一份拷贝
class A1 : virtual public A{
	
};

class A2 :virtual public A{
	
};

class B:public A1, public A2{

};

int main(){
	B b;
	//二义性 sex不明确
	//消除二义性方法1，显示调用，比较麻烦
	b.A1::sex = 1;
	//采用虚继承可以这么写 b.sex = 1;

	

}
