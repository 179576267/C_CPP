#include<stdio.h>
/**
指针运算,指针的所有四则运算都是位置的改变 p + 1 = p的物理地址 + 1个该指针所对应类型占用的字节数 
**/
void cal(){
int ids[] = {12,45,4512,12213,3};
//数组变量名就是数组的首地址
printf("%#x\n", ids);
printf("%#x\n", &ids);
printf("%#x\n", &ids[0]);
int *p = ids;
	
int index = 0;
int length=sizeof(ids)/sizeof(ids[0]); 
for(;index<length;index++){
	printf("%d\n", *(p++));
}
}

void main(){
cal();
printf("size of float:%d\n", sizeof(float));
int a = 8;
int *pa = &a;
printf("%#x     %d\n", pa, *pa);

}
