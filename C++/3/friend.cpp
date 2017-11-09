#include"../header.h"

//友元访问一些私有属性
//友元函数
class A{
	//B可以访问A的任何成员
	friend class B;
	private :
		int i;
	public:
		A(int i){ this->i = i;} 
		void myprintf(){ cout<< i<< endl;}
		//友元函数声明
		friend void modify_i(A *p, int a);
};

class B{
	private:
	A a;

	public:
	void accessAny(){
		//本来在B里面通过a访问i是不行的，但是在A里面添加友元类就可以了
		a.i = 10;
	}


};

//友元函数实现，在友元函数中可以访问四有属性
void modify_i(A *p, int a){
	p->i = a;
}

int main(){
	A *a = new A(10);
	a->myprintf();
	modify_i(a, 20);
	a->myprintf();	
	

}
