#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encode(char *src, char *des, char pwd[]){
	FILE *src_fp = fopen(src, "rb");
	if(src_fp == NULL){
		printf("src error!\n");
		return;	
	}
	FILE *des_fp = fopen(des, "wb");
	
	int ch;
	int i = 0;//循环使用密码中的字符进行异或
	int pwd_len = strlen(pwd);
	printf("++++++++++++++++++++++++++++++++++\n");
	while((ch = fgetc(src_fp)) != EOF){
		printf("%c", pwd[i % pwd_len]);
		fputc(ch ^ pwd[i % pwd_len], des_fp);
		i++;
	}
	
	fclose(src_fp);
	fclose(des_fp);
}

void decode(char *src, char *des, char pwd[]){
	FILE *src_fp = fopen(src, "rb");
	if(src_fp == NULL){
		printf("src error!\n");
		return;	
	}
	FILE *des_fp = fopen(des, "wb");
	printf("++++++++++++++++++++++++++++++++++\n");
	int ch;
	int i = 0;//循环使用密码中的字符进行异或
	int pwd_len = strlen(pwd);
	while((ch = fgetc(src_fp)) != EOF){
		fputc(ch ^ pwd[i % pwd_len], des_fp);
		i++;
	}

	fclose(src_fp);
	fclose(des_fp);
}



void main(){
	char *src_path = "./1.jpg";
	char *en_path = "./1_encode.jpg";
	char *de_path = "./1_decode.jpg";
	char *pwd = "wangzhenfei";
		
	encode(src_path, en_path, pwd);
	decode(en_path, de_path, pwd);
}
