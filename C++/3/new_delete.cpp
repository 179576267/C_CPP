#include"../header.h"

//c++ 通过new（delete）动态分配内存
//c   通过malloc（free）动态分配内存


class Teacher{
	private:
		char *name;
	public :
		Teacher(char *n){
			this->name = n;
			cout << "teacher"<<endl;
		}
		
		char * getName(){
			return name;
		}

		void setName(char *n){
			this->name = n;
		}
		~Teacher(){cout << "~teacher"<<endl;}
		
};

void func1(){
	//c++ 调用构造函数和析构函数
	Teacher *t1 = new Teacher("wzf");
	cout << t1->getName() <<endl;
	//new 出来的对象是在堆内存，是动态内存，需要手动释放
	//不加delete Teacher的析构函数不会调用
	delete t1;

	//c 不会调用构造函数和析构函数
	Teacher *t2 = (Teacher *)malloc(sizeof(Teacher));
	t2->setName("qwe");
	cout << t2->getName() <<endl;
	free(t2);
}

void func2(){
	//c
	int *p1 = (int *) malloc (sizeof(int) * 10);
	p1[0] = 9;
	free(p1);

	//c++
	int *p2 = new int[10];
	//java 
 //int []p2 = new int[10];
	p2[3] = 8;
	//释放数组 加上【】
	delete[]p2;


}

int main(){
	func1();
	func2();
}
