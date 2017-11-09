#include"../header.h"


//继承，子类对象调用父类成员
class Parent1{
	private:
		int age;
	public:
		int sex;
		Parent1(int age){
			this->age = age;
			cout << "parent1 构造函数" << endl;
		}
		void say(){
			cout << "parent1 say" << endl;
		}
		
		~Parent1(){
			cout << "parent1 析构函数" << endl;	
		}
};

class Parent2{
	private:
		int age;
	public:
		int sex;
		Parent2(int age){
			this->age = age;
			cout << "parent2 构造函数" << endl;
		}
		void say(){
			cout << "parent2 say" << endl;
		}
		
		~Parent2(){
			cout << "parent2 析构函数" << endl;	
		}
};

//多继承， 大部分90%都是public 继承方式
//子类的private修饰， 无论什么继承方式，子类都不能访问private
//子类所继承的元素为继承方式和基类内访问修饰符最小的权限
class Child : public Parent1, public Parent2{
	private:
		int height;
		Parent1 father1;
		Parent2 father2;
	public:
		int money;
		//：后面先调用父类的构造方法，然后对成员变量赋值
		Child(int height, int age):Parent1(age),Parent2(age), father1(age + 1), father2(age - 1){
			this->height = height;
			cout << "child 构造函数" << endl;
		}

		void say(){
			cout << "child say" << endl;
		}

		~Child(){
			cout << "child 析构函数" << endl;	
		}

};

int main(){
	Child child(12, 32);
	child.say();
	//调用父类的方法
	child.Parent1::say();
	//父类成员赋值，Parent1和Parent2都有
	child.Parent2::sex = 1;
	Parent1 father = child;
	father.say();
	Parent1 *p = &child;
	p->say();


}
