#include"../header.h"

/*
c++  类型转换
statc_cast
const_cast
dynamic_cast
reinterpret_cast

相对于c的，增加可读性，规避自动转换潜在风险
*/

int main(){
	//c类型转换
	int i = 0;
	//自动类型转化
	double d = 9.5;
	//自动类型转换，丢失精度
	int a = d;

	//c++高级转换
	int b = static_cast<int> (d);
}
