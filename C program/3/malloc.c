#include<stdio.h>
#include<math.h>
/**
c语言内存分配
1.栈区（大小为确定的常数，且自动分配和释放，主要存储函数的参数）
2.堆区（手动分配和释放，可以分配操作系统百分之八十的内存）
3.全局区或者静态区
4.程序代码区
**/
void main(){
	//会导致stack overflow
	//静态内存分配，栈内存
	//int a[1024 * 1024 * 10 * 1024] ;

	//HT_NODE  *newnode=(HT_NODE  *) malloc (sizeof(HT_NODE));
	//在堆内存分配40M内存  malloc(字节)
	int *p = malloc(1024 * 1024 * 10 * sizeof(int));

	//释放内存	
	if(p != NULL){
		free(p);	
		p = NULL;
	}
	

	//动态创建数组
	int len = 10;
	//arr是数组的首地址
	int *arr = malloc(len * sizeof(int));
	int i = 0;	
	for(;i<len;i++){
		arr[i] = rand() % 100;
		printf("%#x, %d\n", &arr[i], arr[i]);
	}

	//扩大内存空间 realloc(char* p,int 内存扩大后的总大小)
	//如果重新分配内存缩小的情况，缩小的那部分数据会丢失
	//如果是扩大的情况下，动态内存分配必须是连续的，当扩大的时候导致内存不连续，那么
	//系统就会重新找个够分配的连续内存进行返回。数据会复制。
	//当找不到这么大的内存时候，返回NULL，原来的指针有效。
	int newlen = 10;
	printf("before: %#x\n", arr);
	int * newarr = realloc(arr, (newlen + len) * sizeof(int));
	if(newarr == NULL){
		printf("重新分配内存失败");
	}
	printf("after: %#x\n", arr);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	i = 0;
	for(;i<len + newlen;i++){
		printf("%#x, %d\n", &arr[i], arr[i]);
	}
	if(arr != NULL){
		free(arr);
		arr == NULL;
	}
	//内存分配细节注意
	/*
	1.free不能多次释放,所以释放完毕，将指针置为空，标志为释放完成
	2.内存泄露（p重新赋值后再free，这样p所指向的地址变化了，原来申请的地址无法访问到，且无法释放）
	*/
}
