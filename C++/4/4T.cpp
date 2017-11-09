#include"../header.h"


//函数模板（泛型）
void swap(int &a, int &b){
	int tem = a;
	a = b;
	b = tem;

}
//写成泛型
template <typename T>
void myswap(T &a, T &b){
	T tem = a;
	a = b;
	b = tem;
}

int main(){
	int a = 3;
	int b = 5;
	myswap<int>(a, b);
	cout<< a << " : " << b << endl;

	char c = 'h';
	char d = 'q';
	myswap(c, d);
	cout << c << " : " << d << endl;

}
