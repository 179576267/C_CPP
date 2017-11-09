#include"../header.h"

class Point{
	
	friend Point operator*(Point &a,Point &b);
	private:
		int a;
		int b;
	public:
		int x;
		int y;
		Point(int x, int y){
			this->x = x;
			this->y = y;
			this->a = x;
			this->b = y;
		}

		//成员函数运算符重载
		Point operator+(Point &b){
		Point temp(this->x + b.x, this->y + b.y);
		return temp;
		}
		void myprintf(){
			cout << x << " , " << y << endl;
		}
	
};
//运算符重载+ 外部写法  java String 也是
//Point operator+(Point &a, Point &b){
//	Point temp(a.x + b.x, a.y + b.y);
//	return temp;
//}

//友元函数 运算符重载
Point operator*(Point &a, Point &b){
	Point temp(a.a * b.a, a.b * b.b);
	return temp;}

Point operator-(Point &a, Point &b){
	Point temp(a.x - b.x, a.y - b.y);
	return temp;
}

int main(){
	Point p1(10,20);
	Point p2(15,23);
	Point p3 = p1 * p2;
	p3.myprintf(); 
	Point p4 = p1.operator+(p2);
	p4.myprintf(); 
}
