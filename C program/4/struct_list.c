#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//字节对齐，4位一读取，多了空置
typedef struct{
	int id;
	char name[13];
	int gender;
} User, *User_p;

typedef struct user_node{
	User user;
	struct user_node *next;
}User_Node;

void printfUser(User_Node *p_header){
	while(p_header != NULL){
		printf("%d, %s, %s\n", p_header->user.id,
										p_header->user.name,
										p_header->user.gender == 1? "boy" : "girl");
		p_header = p_header->next;	
	}
}

//头插入
void insertStart(User_Node *p_header, User_Node *p_new){	
	if(p_header == NULL || p_new == NULL){
		printf("节点为空\n");
		return;
	}

	if(p_header->next == NULL){
		p_header->next = p_new;
	}else{
		p_new->next = p_header->next;
		p_header->next = p_new;
	}
	
}

//头插入
void insertWithNewStart(User_Node *p_header,int id, char *name, int gender){
	if(p_header == NULL){
		printf("头节点为空\n");
		return;
	}
	User_Node *p_new = (User_Node*)malloc(sizeof(User_Node));
	p_new->user.id= id;
	strcpy(p_new->user.name, name);
	p_new->user.gender = gender;

	if(p_header->next == NULL){
		p_header->next = p_new;
	}else{
		p_new->next = p_header->next;
		p_header->next = p_new;
	}
	
}


void insertWithNewEnd(User_Node *p_header,int id, char *name, int gender){
	//尾插入
	if(p_header == NULL){
		printf("头节点为空\n");
		return;
	}
	User_Node *p_new = (User_Node*)malloc(sizeof(User_Node));
	p_new->user.id= id;
	strcpy(p_new->user.name, name);
	p_new->user.gender = gender;

	while(p_header->next){
		p_header = p_header->next;
	}
	p_header->next = p_new;
	
}

void freeall(User_Node *p_header){
	User_Node *p_now = p_header;
	User_Node *p_next;

	while(p_now != NULL){
		p_next = p_now->next;
		free(p_now);
		p_now = p_next;	
		p_next = NULL;
	}
}

void main(){
	//初始化头结点
	printf("User size : %d\n", sizeof(User));
	User_Node * header = (User_Node *)malloc(sizeof(User_Node));

	header->user.id = 0;
	strcpy(header->user.name, "first");
	header->user.gender = 1;

	printf("头插入\n");
	insertWithNewStart(header, 1, "wang", 2);
	insertWithNewStart(header, 2, "zhen", 1);
	insertWithNewStart(header, 3, "fei", 2);
	insertWithNewStart(header, 4, "hello", 1);
	insertWithNewStart(header, 5, "world", 2);
	printf("尾插入\n");
	insertWithNewEnd(header, 1, "wang", 2);
	insertWithNewEnd(header, 2, "zhen", 1);
	insertWithNewEnd(header, 3, "fei", 2);
	insertWithNewEnd(header, 4, "hello", 1);
	insertWithNewEnd(header, 5, "world", 2);



	printfUser(header);
	freeall(header);

}
