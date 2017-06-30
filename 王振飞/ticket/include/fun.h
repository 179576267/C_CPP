#include"list.h"

int enroll(USER_NODE *head);//用户注册函数

int sign_in(USER_NODE *p,ABT_NODE *q,HT_NODE *r,CHARGE_NODE *t);//用户登录函数

void user_write(USER_NODE *head);//用户信息写入函数
void user_read(USER_NODE *head);//用户信息读取函数

void abt_write(ABT_NODE *head);//彩票信息写入函数
void abt_read(ABT_NODE *head);//彩票信息读取函数

void ht_write(HT_NODE *head);//历史记录写入函数
void ht_read(HT_NODE *head);//历史记录读取函数

void charge_write(CHARGE_NODE  *head);//充值记录写入函数
void charge_read(CHARGE_NODE  *head);//充值记录读取函数

void all_free(USER_NODE *p,ABT_NODE *q,HT_NODE *r,CHARGE_NODE *t);//释放申请空间
