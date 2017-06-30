#include "stdio.h"

//
// Created by Administrator on 2017/6/27.
//
//JNIEnv结构体的指针别名
typedef const struct JNINativeInterface_* JNIEnv;

//结构体
struct JNINativeInterface_{
    char* (*NewStringUTF) (JNIEnv*, char*);
};

//函数实现
char* NewStringUTF(JNIEnv* env, char* str){
    printf("%s\n", str);
    return str;
}

void main(){
    //实例化结构体
    struct JNINativeInterface_ struct_env;
    struct_env.NewStringUTF = NewStringUTF;
    //结构体指针
    JNIEnv e = &struct_env;
    JNIEnv *env = &e;
    (*env)->NewStringUTF(env,"123");


    char str[][6] = {"abcd", "ABC", "abc"};  
	//这个会显示出二维数组中每个行的元素个数 （这里指可容纳的个数） 
    printf("str行内元素: %d\n", sizeof(*str));
	//这个会显示出二维数组中元素的个数（这里是指可容纳的个数） 
    printf("str总: %d\n", sizeof(str));
 
    //其实就是利用了sizeof函数来判断 我们都知道sizeof()用来判断一个类型所占用的字节数的
    //所以:你问‘C语言二维字符串数组的行数怎么求啊？’ 你应该是说在定义数组
	//时候没有显示的写出行数，可是此时需要求出行数是吧？
    //那么 行数 = 可容纳元素总数（这里是指可容纳的个数） / 行中元素个数（这里是指可容纳的个数）
    printf("行数:  %d\n", sizeof(str)/sizeof(*str)
);
	return;


}

