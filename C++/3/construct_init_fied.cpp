#include"../header.h"

//构造函数的属性初始化列表
class Teacher{
	private:
		char *name;
	public :
		Teacher(char *n){
			this->name = n;
			cout << "teacner"<<endl;
		}
		
		char * getName(){
			return name;
		}
		~Teacher(){cout << "~teacner"<<endl;}
		
};

class Student{
	private:
		int id;
		Teacher t;
	public :
		int _age;
		//构造给成员对象变量赋值
		Student(int id, int age, char *t_name):t(t_name),_age(id * 5){
			this->id = id;
			cout << "student"<<endl;	
		}

		Teacher getT(){
			return t;
		}

		int getId(){
			return id;
		}

		~Student(){
			cout << "~student"<<endl;		
		}
};

/**
*teacner
*student
*~student
*~teacner
*属性先创造，对象先析构 后进先出
*/
void func(){
	Student s1(1, 100, "wzf");
	//cout << s1.getT().getName() << " : " << s1.getId() << "," << s1._age <<endl;
}

int main(){
	func();
}

