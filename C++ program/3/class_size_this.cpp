#include "../header.h"

//this 当前对象的指针
//函数是共享的存在与代码区，必须要有能够标识当前对象的办法
//this 不能修改，const A * const this  即是常量指针，又是指针常量  值本生不能改，指向也不能修改
class A{
	public:
	int i;
	int j;
	int k;
	static int m;
};


class B{
	public:
	int i;
	int j;
	int k;
	void myprintf(){
		cout << "print" << endl;
	}

	void myprintf2() const{
		//const常函数 不能修改属性 i = 0，防止成员被非法修改;
		cout << "print" << endl;
	}
};

int main(){
	//都是12
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	
	const B b;
	//常量对象只能调用常量函数， 非常量对象也可以调用常量函数
	b.myprintf2();
	
	//c c++ 内存分区 ： 栈，堆，全局（静态，全结），常量区（字符串），代码区
	//c++ 类的普通属性与结构体有着相同的内存布局，静态成员是放在全局区，函数放在代码区

}
