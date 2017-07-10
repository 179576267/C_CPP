#include"../../header.h"
#include"Jet.h"
#include"Copter.h"
void Plane::fly(){cout << "fly" << endl;}
void Plane::land(){cout << "land" << endl;}

void Jet::fly(){cout << "fly in Jet" << endl;}
void Jet::land(){cout << "land in Jet" << endl;}

void Copter::fly(){cout << "fly in Copter" << endl;}
void Copter::land(){cout << "land in Copter" << endl;}

void func(Plane &p){
	p.fly();
	p.land();
}

//虚函数使用场景1
//有纯虚函数的类就是抽象类
class Shape{
	public:
		//纯虚函数
		virtual void sayArea() = 0;
};

//继承抽象类，必须要实现，否则也是抽象类，不能实例化对象，类似java
class Circle : public Shape{
	private:
		int r;
	public:
		Circle(int r){this->r = r;}
		
		void sayArea(){
			cout << "area is : " << 3.14 * r * r << endl;
		}
};

//接口（只是逻辑上的划分，只是语法上和抽象类没有实质区别）
//只有纯虚函数（加上 = 0），没有实现了的函数
class Draw{
	virtual void draw() = 0;
}

//虚函数使用场景2: 解决二义性

//虚函数使用场景3
// 多态（程序的扩展性）1.继承，2.父类引用或者指针指向子类的对象，3.重写方法
//动态多态：程序在运行过程中，觉得哪一个函数被调用（重写,覆盖）
//静态多态：重载



int main(){
	Plane p1;
	func(p1);
	//若不在被覆写的父类方法加上virtual关键字 否则无法完成多态，还是会调用父类的方法
	Jet p2;
	func(p2);
	
	Copter p3;
	func(p3);

	Circle c(10);
	c.sayArea();
}
