#include<stdio.h>
#include<stdlib.h>

void readTxt(){
	char path[] = "./friends.txt";
	FILE *fp = fopen(path, "r");
	if(fp == NULL){
		printf("打开文件失败\n");
		return;
	}

	//读取
	char buff[50];//缓冲
	while(fgets(buff, 50, fp)){
		printf("%s", buff);
	}

	if(fclose(fp)){
		printf("error fclose!\n");
		exit(-1);
	}

}

void writeTxt(){
	char path[] = "./friendsNew.txt";
	FILE *fp = fopen(path, "w");
	if(fp == NULL){
		printf("打开文件失败\n");
		return;
	}

	//写入
	char *text = "hahahahhahahahahhahaha佛教哦iwejfiew";
	fputs(text, fp);

	if(fclose(fp)){
		printf("error fclose!\n");
		exit(-1);
	}

}

//二进制文件操作
//c在读写文本文件和二进制文件差别在于回车换行符号
//写文本时，每遇到一个‘\n’，会将其转换为'\r\n'(回车换行)
//读文本时，每遇到一个‘\r\n’，会将其转换为'\n'
void copyFile(){	
	//读的文件 b 表示二进制
	char *read_path = "./1.jpg";
	char *write_path = "./3.jpg";
	FILE *read_fp = fopen(read_path, "rb");

	//获取文件大小
	//函数把文件指针移到fromwhere所指位置的向后offset个字节处,fromwhere
	fseek(read_fp, 0, SEEK_END);
	//当前的文件指针相对于文件头的偏移量	
	long file_size = ftell(read_fp);
	printf("file size is :%ld\n", file_size);

	fseek(read_fp, 0, SEEK_SET);
	FILE *write_fp = fopen(write_path, "wb");
	if(read_fp == NULL){
		printf("打开文件失败\n");
		return;
	}

	char buff[50];//缓冲区
	int len = 0;//每次读到的真实长度
	//int fread(void *ptr,int size,int nitems,FILE *stream)
	//从流stream中读入nitems个长度为size的字符串存入ptr中
	while((len = fread(buff, sizeof(char), 50, read_fp)) != 0){
		//int fwrite(void *ptr,int size,int nitems,FILE *stream)
		//向流stream中写入nitems个长度为size的字符串,字符串在ptr中
		fwrite(buff, sizeof(char), len, write_fp);
	}


	if(fclose(read_fp)){
		printf("error fclose read_fp!\n");
		exit(-1);
	}

	if(fclose(write_fp)){
		printf("error fclose write_fp!\n");
		exit(-1);
	}
}

void main(){
	//writeTxt();
	//readTxt();
	copyFile();
}
