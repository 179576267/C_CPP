//只有函数的申明，编译的时候找函数的实现
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void waigua(){
	int time = 600;
	printf("time的内存地址为：%#x\n", &time); 
	while(time > 0){
		printf("剩余时间游戏：%d\n", time--);
		sleep(1);	
	}
}

void main(int argc, char* argv){
	waigua();
	/**
	int %d,
	short %d,
	long %ld,
	float %f,
	double %lf,
	char %c,
	%x 16
	%o 8
	char * %s
	sizeofd 
	**/
	int i = 1;
	printf("%d\n", 1 * 100);

	float f = 123.34;
	printf("%f\n", f); 

	short sh = 4;
	printf("%d\n", sh);

	int j = 0 ;
	
	for(j = 0 ; j < 10; j++){
		printf("%d\n",j * 100);
	}

	/** window平台支持 linux不支持，尽量使用上面的c标准格式
	for(int j = 0 ; j < 10; j++){
		printf("%d\n",j * 100);
	}
	
	int a = -1;
	printf("请输入一个整数：");
	scanf("%d", &a);
	fflush(stdin); 
	while(a = -1){
		printf("输入有错误，请重新输入一个整数：");
		scanf("%d", &a);
		fflush(stdin); 
	}
	printf("输入的整数为: %d\n", a);
	**/
	printf("i=%d\n", i); 	
	int* p =&i;
	printf("p的内存地址为：%#x\n", p); 
	*p = 	210;
	printf("i=%d\n", i); 	

}
