#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体是一种构造数据类型


typedef struct struct_man
{
	int id;//用户ID
	char name[20];
	char pwd[20];
	float money;//用户余额

}USER;//彩民信息结构体

typedef struct user_node
{
	USER user;
	struct user_node *next;
}USER_NODE;//彩民链表

//struct_man可以省略，匿名结构体,用于控制结构体变量的个数(此例子就两个u1，u2)
struct 
{
	int id;//用户ID
	char name[20];
	char pwd[20];
	float money;//用户余额

}u1,u2;//彩民信息结构体       只有两个成员变量

//结构体嵌套
typedef struct {

	char name[20];
	
} Teacher;


typedef struct{
	char pwd[20];
	int age;
	Teacher t;
	//函数指针
	void(*sayHi)(char *, int);
	struct School{//可以外部引用
		char name[20];
	}s;
}Student;

void printfUser(USER user){
	printf("%d %s %s %f\n", user.id, user.name, user.pwd, user.money);
}

void talk(char *s, int a){
	printf("hello world %s, is %d\n", s, a);
}

void main(){
	//{}只能在声明的时候赋值，java的数组初始化类似
	USER user1 = {1, "wang", "111111", 1.1f};
	USER user2;
	struct struct_man user3;
	user2.id = 2;
	strcpy(user2.name, "zhen");
	strcpy(user2.pwd, "222222");
	user2.money = 2.0f;

	user3.id = 3;
	strcpy(user3.name, "fei");
	strcpy(user3.pwd, "333333");
	user3.money = 3.0f;

	printfUser(user1);
	printfUser(user2);
	printfUser(user3);

	
	Student stu1 = {"qqq", 20, {"wzf"}};
	stu1.sayHi = talk; //函数指针赋值
	stu1.sayHi("say", 200);//函数指针调用
	Student *p = &stu1;
	p->sayHi = talk;


	Student stu2;
	strcpy(stu2.t.name, "zhen");
	strcpy(stu2.s.name, "fei");




}
